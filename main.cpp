#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> count(128, 0);
    int left = 0, right = 0, max_len = 0;
    for(left = 0; left < s.size(); left++) {
        while(right < s.size() && count[s[right]] == 0) {
            count[s[right]]++;
            right++;
        }
        count[s[left]]--;
        max_len = max(max_len, right - left);
    }
    return max_len;
}

int main() {
    string a = "abcabcbb";
    cout << lengthOfLongestSubstring(a) << endl;
    return 0;
}

/* 
O(26n) solution

For each 26 letter segment, we check if number of distinct letters + number ? == 26
   - If so, 
      - fill in ? in the segment with the unseen letters. 
      - fill in ? outside the segment with 'A'
   - If not, continue to the next segment
If none of the segments work, output -1
*/
#include <string>
#include <iostream>
using namespace std;

int freq[200];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    for (int start = 0; start <= n-26; start++) {
        for (int l = 'A'; l <= 'Z'; l++) {
            freq[l] = 0;
        }
        freq['?'] = 0;

        int numDistinct = 0;
        for (int i = start; i < start+26; i++) {
            freq[s[i]]++;
            if (freq[s[i]] == 1 && s[i] != '?') {
                numDistinct++;
            }
        }
        //cout << numDistinct << " " << freq['?'] << '\n';
        if (numDistinct + freq['?'] == 26) {
            for (int i = start; i < start+26; i++) {
                if (s[i] == '?') {
                    for (int l = 'A'; l <= 'Z'; l++) {
                        if (!freq[l]) {
                            freq[l]++;
                            s[i] = l;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    s[i] = 'A';
                }
            }
            cout << s << "\n";
            return 0;
        }
    }
    cout << "-1" << "\n";
}
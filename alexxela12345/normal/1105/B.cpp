#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int cur_ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                cur++;
            } else {
                cur = 0;
            }
            if (cur == k) {
                cur_ans += 1;
                cur = 0;
            }
        }
        ans = max(ans, cur_ans);
    }
    cout << ans << endl;
    return 0;
}
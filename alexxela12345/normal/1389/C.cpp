#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(10);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - '0']++;
        }
        int best_ans = n;
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                bool lasta = false;
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (!lasta && s[i] - '0' == a) {
                        lasta = true;
                    } else if (lasta && s[i] - '0' == b) {
                        lasta = false;
                    } else {
                        cnt++;
                    }
                    if (cnt >= best_ans)
                        break;
                }
                if (lasta && cnt != n - 1 && a != b) {
                    cnt++;
                }
                best_ans = min(best_ans, cnt);
            }
        }
        cout << best_ans << endl;
    }
}
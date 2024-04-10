#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> now(26);
        vector <bool> now1(26);
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            ++now[c - 'a'];
            now1[c - 'a'] = true;
        }
        for (int i = 24; i >= 0; --i) {
            now1[i] = now1[i] || now1[i + 1];
        }
        vector <string> ans(k);
        int kol = 0;
        bool flag = false, minn = false;
        int minn1 = 0;
        for (int i = 0; i < 26; ++i) {
            if (!flag) {
                while (kol < k && now[i] > 0) {
                    ans[kol].push_back(i + 'a');
                    ++kol;
                    --now[i];
                }
                if (kol == k) {
                    flag = true;
                    --i;
                    if (ans[0] != ans[k - 1]) {
                        minn = true;
                        minn1 = k - 1;
                    }
                }
            }
            else if (minn) {
                while (now[i] > 0) {
                    ans[0].push_back(i + 'a');
                    --now[i];
                }
            }
            else {
                if (now[i] == 0) continue;
                if (i != 25 && now1[i + 1]) {
                    while (now[i] > 0) {
                        ans[0].push_back(i + 'a');
                        --now[i];
                    }
                    minn = true;
                }
                else {
                    int ch = 0;
                    while (now[i] > 0) {
                        ans[ch].push_back(i + 'a');
                        --now[i];
                        ++ch;
                        if (ch == k) ch = 0;
                    }
                }
            }
        }
        cout << ans[minn1] << "\n";
    }
}
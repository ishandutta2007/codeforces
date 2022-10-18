#include <bits/stdc++.h>

using namespace std;

int cnt[11][11];
int ans[11][11];
int inf = 1e9;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i + 1 < n; ++i) {
        cnt[s[i] - '0'][s[i + 1] - '0']++;
    }
    bool f;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int ans = 0;
            f = false;
            for (int z = 0; z < 10; ++z) {
                for (int k = 0; k < 10; ++k) {
                    if (cnt[z][k] == 0) continue;
                    int imin = inf;
                    for (int d = 0; d <= 10; ++d) {
                        for (int f = 0; f <= 10; ++f) {
                            if (k == z && max(d, f) == 0) continue;
                            if ((d * i + f * j + z) % 10 == k) {
                                imin = min(imin, d + f);
                            }
                        }
                    }
                    if (imin == inf) f = true;
                    ans += imin * cnt[z][k];
                }
            }
            if (f) cout << -1 << " ";
            else cout << ans + 1 - (int)s.size() << " ";
        }
        cout << '\n';
    }
    return 0;
}
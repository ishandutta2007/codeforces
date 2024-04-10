#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
int q;
const int BUBEN = 30;
const int maxN = 5 * (int)1e5 + 100;
ld dp[maxN][BUBEN + 2];
int prv[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> q;
    for (int i = 0; i <= BUBEN; i++) {
        dp[1][i] = 1;
    }
    int sz = 2;
    for (int i = 1; i <= q; i++) {
        int tp, v;
        cin >> tp >> v;
        if (tp == 1) {
            int cur_v = sz;
            prv[cur_v] = v;
            sz++;
            int nv = cur_v;
            vector < pair < int, int > > all;
            for (int j = 0; j <= BUBEN; j++) {
                int tv = prv[nv];
                if (tv == 0) continue;
                all.emplace_back(nv, tv);
                nv = tv;
            }
            reverse(all.begin(), all.end());
            for (auto t : all) {
                if (t.first == cur_v) continue;
                for (int k = 1; k <= BUBEN; k++) {
                    if (k >= 1) {
                        dp[t.second][k] /= (1 + dp[t.first][k - 1]);
                    }
                }
            }
            for (int j = 0; j <= BUBEN; j++) {
                dp[cur_v][j] = 1;
            }
            reverse(all.begin(), all.end());
            for (auto t : all) {
                for (int k = 0; k <= BUBEN; k++) {
                    if (k == 0 && t.first == cur_v) {
                        dp[t.second][k] *= 0.5;
                    }
                    else if (k >= 1 && t.first != cur_v) {
                        dp[t.second][k] *= (1 + dp[t.first][k - 1]);
                    }
                }
            }
        }
        else {
            ld ans = BUBEN + 1;
            for (int j = 0; j <= BUBEN; j++) ans -= dp[v][j];
            cout << fixed << setprecision(8) << ans << '\n';
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
const int mod = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int d[n + 1][8][8];
    memset(d, 0, sizeof d);
    d[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 8; j++) {
            for(int k = 0; k < 8; k++) {
                bitset<3> was_les = j;
                bitset<3> was_uni = k;
                int lim[3];
                for(int z = 0; z < 3; z++) {
                    lim[z] = (was_les[z] || s[i - 1] == '1') ? 1 : 0;
                }
                int nbit[3];
                bitset<3> nles, nuni;
                for(nbit[0] = 0; nbit[0] <= lim[0]; nbit[0]++)
                for(nbit[1] = 0; nbit[1] <= lim[1]; nbit[1]++)
                for(nbit[2] = 0; nbit[2] <= lim[2]; nbit[2]++) {
                    for(int z = 0; z < 3; z++) {
                        nles[z] = was_les[z] | (nbit[z] < lim[z]);
                        int nz = z + 1, nzz = z + 2;
                        if(nz >= 3) nz -= 3;
                        if(nzz >= 3) nzz -= 3;
                        nuni[z] = was_uni[z] | (nbit[z] != nbit[nz] && nbit[z] != nbit[nzz]);
                    }
                    int &x = d[i][nles.to_ulong()][nuni.to_ulong()];
                    x += d[i - 1][j][k];
                    if(x >= mod) {
                        x -= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 8; i++) {
        ans += d[n][i][7];
        if(ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
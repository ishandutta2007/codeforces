#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 300005, logg = 19;
int a[maxn], c[maxn];
int dp[logg][maxn];

int get(int v) {
    for (int j = logg - 1; j >= 0; --j) {
        if (a[dp[j][v]] == 0) continue;
        v = dp[j][v];
    }
    return v;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, type, v, w;
    cin >> q >> a[0] >> c[0];
    for (int i = 1; i <= q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> dp[0][i] >> a[i] >> c[i];
            for (int j = 1; j < logg; ++j) {
                dp[j][i] = dp[j - 1][dp[j - 1][i]];
            }
        }
        else {
            cin >> v >> w;
            int W = 0;
            ll C = 0;
            while (w && a[v]) {
                int go = get(v);
                int T = min(w, a[go]);
                a[go] -= T;
                C += (ll)T * (ll)c[go];
                w -= T;
                W += T;
            }
            cout << W << " " << C << endl;
        }
    }
    return 0;
}
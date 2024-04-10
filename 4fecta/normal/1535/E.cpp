#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005, LOG = 19;

int q, t, x, u, v, par[MN], bl[MN][LOG], psa[MN];
pii a[MN]; //quantity, cost;

int32_t main() {
    boost();

    cin >> q >> a[0].f >> a[0].s;
    psa[0] = a[0].f;
    for (int i = 1; i <= q; i++) {
        cin >> t >> x;
        if (t == 1) {
            cin >> u >> v;
            a[i] = {u, v};
            par[i] = x;
            bl[i][0] = x;
            psa[i] = psa[x] + u;
            for (int j = 1; j < LOG; j++) bl[i][j] = bl[bl[i][j - 1]][j - 1];
        } else {
            cin >> v; //amt to buy
            int amt = 0, cost = 0;
            while (1) {
                int p = x;
                for (int j = LOG - 1; j >= 0; j--) if (a[bl[p][j]].f) p = bl[p][j]; //p is now lowest non-zero
                if (!a[p].f) break;
                if (v - amt <= a[p].f) {
                    cost += (v - amt) * a[p].s;
                    a[p].f -= v - amt;
                    amt = v;
                } else {
                    cost += a[p].f * a[p].s;
                    amt += a[p].f;
                    a[p].f = 0;
                }
                if (amt == v) break;
            }
            cout << amt << " " << cost << endl;
        }
    }

    return 0;
}
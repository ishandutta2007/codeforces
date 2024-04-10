#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100017;
int V[MAX], c[MAX], n, q;
long long best[MAX];
const long long INF = 1e17;

#define max(a,b) ((a)>(b)?(a):(b))
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> V[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    while (q--) {
        int a, b;
        cin >> a >> b;
        long long mx1 = -INF, mx2 = -INF, c1 = -1, c2 = -1;

        fill_n(best, MAX, -INF);
        long long ans = 0;

        for (int i = 1; i <= n; ++i) {
            best[c[i]] = max(best[c[i]] + 1ll * a * V[i], best[c[i]]);
            best[c[i]] = max(best[c[i]], b * V[i]);
            best[c[i]] = max(best[c[i]], (c1 == c[i] ? mx2 : mx1) + 1ll * b * V[i]);

            long long mx3 = -INF, c3 = -1;
            if (c1 == c[i]) mx1 = best[c[i]];
            else if (c2 == c[i]) mx2 = best[c[i]];
            else mx3 = best[c[i]], c3 = c[i];
            if (mx1 < mx2) swap(mx1, mx2), swap(c1, c2);
            if (mx1 < mx3) swap(mx1, mx3), swap(c1, c3);
            if (mx2 < mx3) swap(mx2, mx3), swap(c2, c3);
        }

        cout << max(mx1, 0) << endl;
    }
}
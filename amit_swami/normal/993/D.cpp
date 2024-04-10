#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

ll d[55][30][3000];

pair<int, int> a[55];

void upd(ll &x, ll y) {
    x = min(x, y);
}


int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i].first);
    forn(i, n) scanf("%d", &a[i].second);

    sort(a, a + n);
    reverse(a, a + n);
    
    memset(d, 63, sizeof d);
    ll INF = d[0][0][0];

    d[0][0][0] = 0;

    forn(i, n) {
        int ii = i;
        while (ii < n && a[ii].first == a[i].first) ii++;

        int k = ii - i;
        for (int j = 0; j * 2 <= i; j++) for (int s = 0; s < 3000; s++) if (d[i][j][s] != INF) {
            int x = i - j;
            int y = j;
            int z = x - y;
            long long sa = 0;
            int sb = 0;
            if (k <= z) {
                upd(d[ii][j + k][s], d[i][j][s]);
            }
            forn(p, k) {
                sa += a[i + p].first;
                sb += a[i + p].second;
                if (k - p - 1 <= z) {
                    upd(d[ii][j + k - p - 1][s + sb], d[i][j][s] + sa);
                }
            }
        }
    }

    //forn(i, n + 1) for (int j = 0; j * 2 <= i; j++) for (int s = 0; s < 3000; s++) if (d[i][j][s] != INF) err("%d %d %d ---> %lld\n", i, j, s, d[i][j][s]);


    ll res = INF;
    for (int j = 0; j * 2 <= n; j++) for (int s = 0; s < 3000; s++) if (d[n][j][s] != INF) {
        res = min(res, (d[n][j][s] * 1000 + s - 1) / s);
    }

    printf("%lld\n", res);

    return 0;
}
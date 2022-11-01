#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 81;
const int M = 1e3 + 10;

int d[N][N][N][2];
int a[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k1;
    cin >> n >> k1;
    int m;
    cin >> m;
    fr(i, n)
        fr(j, n)
            a[i][j] = INF;
    fr(i, m) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        a[v][u] = min(a[v][u], w);
    }

    fr(i1, n) fr(i2, n) fr(i3, n) fr(i4, 2) d[i1][i2][i3][i4] = INF;
    fr(l, n)
        frab(r, l, n)
            frab(v, l, r + 1)
                d[l][r][v][0] = 0;

    frab(k, 1, k1) {
        fr(i1, n) fr(i2, n) fr(i3, n) d[i1][i2][i3][k%2] = INF;
        fr(l, n)
            frab(r, l, n)
                frab(v, l, r + 1)
                    frab(t, l, r + 1)
                        if (t != v) {
                            if (t < v)
                                d[l][r][v][k % 2] = min(d[l][r][v][k % 2], d[l][v - 1][t][(k + 1) % 2] + a[v][t]);
                            else if (t > v)
                                d[l][r][v][k % 2] = min(d[l][r][v][k % 2], d[v + 1][r][t][(k + 1) % 2] + a[v][t]);
                        }
    }

    int ans = INF;
    fr(i, n)
        ans = min(ans, d[0][n - 1][i][(k1 + 1) % 2]);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}
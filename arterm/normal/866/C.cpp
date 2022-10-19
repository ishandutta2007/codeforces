// vim:ts=4:sts=4:sw=4:et
// MOSCOW IPT JINOTEGA
// Table #14
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef long long i64;

const int M = 53;
const int S = 120;
const ld INF = 1e18;
const ld inf = 1e15;
const int ITER = 100;

ld e[M][M * S];
int n, r;
int f[M], t[M];
ld p[M];

void read() {
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int prob;
        cin >> f[i] >> t[i] >> prob;
        p[i] = 0.01 * prob;
    }
}

void uin(ld &x, ld y) {
    x = min(x, y);
}

ld E(int i, int j, ld x = e[0][0]) {
    if (j > r)
        return j + x;
    else
        return e[i][j];
}

ld calc(ld x) {
    for (int i = 0; i <= n; ++i)
        for (int s = 0; s <= r; ++s)
            e[i][s] = INF;

    for (int s = 0; s <= r; ++s)
        e[n][s] = s;


    for (int i = n - 1; i >= 0; --i)
        for (int s = 0; s <= r; ++s) {
            uin(e[i][s], p[i] * E(i + 1, s + f[i], x) + (1 - p[i]) * E(i + 1, s + t[i], x));
            uin(e[i][s], s + x);
        }

    return e[0][0];
}

//void ini() {
    //for (int i = 0; i <= n; ++i)
        //for (int s = 0; s < M * S; ++s)
            //e[i][s] = INF;

    //for (int s = 0; s <= r; ++s)
        //e[n][s] = s;
//}

//void iter() {
    //for (int i = n - 1; i >= 0; --i)
        //for (int s = 0; s <= r; ++s) {
            //uin(e[i][s], p[i] * E(i + 1, s + f[i]) + (1 - p[i]) * E(i + 1, s + t[i]));
            //uin(e[i][s], s + e[0][0]);
        //}
//}

void kill() {
    ld l = 0, r = inf;

    for (int i = 0; i < ITER; ++i) {
        ld x = (l + r) / 2;
        ld y = calc(x);
        if (y < x)
            r = x;
        else
            l = x;
    }

    cout << l << "\n";
}

int main() {
#ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
#endif
    //ios_base::sync_with_stdio(false);
    //
    cout.precision(13);
    cout << fixed;
    read();
    kill();

    return 0;
}
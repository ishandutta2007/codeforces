#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e16 + 10;
const int M = 55;
const int N = 2e5 + 10;

ll pref[N];
ld prefDiv[N];
ld d[M][N];
ll a[N];
ld prefObr[N];

ld calc(int l, int r) {
    l--, r--;
    ld ans = 0;
    ans += prefDiv[r];
    if (l) ans -= prefDiv[l - 1];
    if (l) ans -= (pref[l - 1] * (prefObr[r] - prefObr[l - 1]));
    return ans;
}

void solve(int i, int jl, int jr, int kl, int kr) {
    if (jl > jr) return;
    int j = (jl + jr) / 2;
    int ansk = -1;
    frab(k, kl, min(kr + 1, j)) {
        if (d[i][j] > d[i - 1][k] + calc(k + 1, j))
            d[i][j] = d[i - 1][k] + calc(k + 1, j), ansk = k;
    }
    solve(i, jl, j - 1, kl, ansk);
    solve(i, j + 1, jr, ansk, kr);
}

int main() {
    //srand(time(NULL));
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, k1;
    cin >> n >> k1;
    fr(i, n) {
        cin >> a[i];
        pref[i] = (i ? pref[i - 1] : 0) + a[i];
        prefObr[i] = (i ? prefObr[i - 1] : 0) + 1. / (ld)a[i];
        prefDiv[i] = (i ? prefDiv[i - 1] : 0) + (ld)pref[i] / (ld)a[i];
    }

    fr(i, k1 + 1)
        fr(j, n + 1)
            d[i][j] = INF;

    d[0][0] = 0;
    frab(k, 1, k1 + 1)
        solve(k, 1, n, 0, n);
    cout << fixed << setprecision(12) << d[k1][n];
}
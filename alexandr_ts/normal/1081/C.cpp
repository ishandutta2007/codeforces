#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e3 + 10;

ll d[N][N];

void add(ll& x, ll y) {
    y %= MOD;
    x = (x + y) % MOD;
}

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    d[1][0] = m;
    frab(i, 1, n)
        fr(j, k + 1) {
            if (!d[i][j]) continue;
            add(d[i + 1][j + 1], d[i][j] * (ll)(m - 1));
            add(d[i + 1][j], d[i][j]);
        }
    cout << d[n][k];
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e2 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, m;
ll a[maxn];
int A[maxn][maxn];
int C[maxn][maxn];
int res[maxn][maxn];
ll k;
void mult(int a[][maxn],int b[][maxn], int c[][maxn]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + a[i][k] * 1ll * b[k][j]) % mod;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            c[i][j] = C[i][j];
        }
    }
}
void binpow(ll x) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res[i][j] = (i == j);
        }
    }
    while(x > 0) {
        if(x & 1) {
            mult(res, A, res);
        }
        x /= 2;
        mult(A, A, A);
    }
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(__builtin_popcountll(a[i]^a[j]) % 3 == 0) A[i][j] = 1;
        }
    }
    binpow(k-1);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += res[i][j];
            ans %= mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
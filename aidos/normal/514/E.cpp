#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
ll cnt[222];
ll dp[222];
struct matrix {
    ll a[111][111];
    matrix() {
        memset(a, 0, sizeof(a));
    }
    matrix operator * (matrix o) {
        matrix d;
        for(int i = 0; i <= 100; i++) {
            for(int j = 0; j <= 100; j++) {
                for(int k = 0; k <= 100; k++) {
                    d.a[i][j] = (d.a[i][j] + a[i][k] * o.a[k][j]) % mod;
                }
            }
        }
        return d;
    }
};
matrix binpow(matrix a, int z) {
    if(z == 1) return a;
    if(z % 2 == 1) {
        return binpow(a, z - 1) * a;
    }
    matrix c = binpow(a, z/2);
    return c * c;
}
void solve() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        cnt[d]++;
    }
    dp[0] = 1;
    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = (dp[i] + dp[i-j] * cnt[j]) % mod;
        }
    }
    ll ans = 0;

    for(int i = 0; i <= min(x, 200); i++) ans = (ans + dp[i]) % mod;

    if(x<=200) {
        cout << ans << "\n";
        return;
    }
    matrix A;
    for(int i = 0; i < 99; i++) {
        A.a[i + 1][i] = 1;
    }
    vector<ll> D;
    for(int i = 101; i <= 200; i++) {
        D.emplace_back(dp[i]);
    }
    D.emplace_back(0);
    for(int i = 0; i < 100; i++) {
        A.a[i][99] = cnt[99 - i + 1];
        A.a[i][100] = cnt[99 - i + 1];
    }
    A.a[100][100] = 1;
    matrix B = binpow(A, x - 200);
    for(int i = 0; i <= 100; i++) {
        ans = (ans + D[i] * B.a[i][100]) % mod;
    }
    cout << ans << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
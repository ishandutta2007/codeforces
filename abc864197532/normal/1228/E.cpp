#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, y = 111222333, N = 500;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    int n, k;
    cin >> n >> k;
    lli C[N][N];
    C[1][0] = C[1][1] = 1;
    fop (i,2,N) {
        C[i][0] = 1;
        fop (j,1,i+1) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
    lli dp[n+1][n+1], ans = 0;
    fop (i,0,n+1) fop (j,0,n+1) {
        dp[i][j] = C[n][i] * C[n][j] % mod * modpow(k, (n - i) * (n - j)) % mod * modpow(k - 1, n * n - (n - i) * (n - j)) % mod;
        if ((i + j) % 2) ans = (ans + mod - dp[i][j]) % mod;
        else ans = (ans + dp[i][j]) % mod;
    }
    cout << ans << endl;
}
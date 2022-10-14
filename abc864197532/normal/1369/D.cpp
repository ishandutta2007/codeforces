#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
const int mod = 1e9 + 7, x = 864197532, N = 2000001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli dp[N][2];
    dp[3][0] = 1;
    dp[3][1] = 0;
    dp[4][0] = 1;
    dp[4][1] = 1;
    auto mx = [&](int x) {
        if (x % 3 == 2) return dp[x][1];
        return dp[x][0];
    };
    fop (i,5,N) {
    	dp[i][1] = (mx(i - 2) * 2 + mx(i - 1)) % mod;
    	dp[i][0] = (dp[i - 2][1] * 2 + dp[i - 1][1] + 1) % mod;
	}
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	cout << mx(n) * 4 % mod << endl;
	}
}
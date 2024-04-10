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
const int mod = 998244353, x = 864197532, N = 200087, logN = 17, K = 350;

lli modpow(lli a, int b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

lli dp[N][2];
int k;

lli solve_dp (int mid, bool same) {
	if (dp[mid][same] != -1) return dp[mid][same];
	if (same) return dp[mid][same] = solve_dp(mid - 1, false) * (k - 1) % mod;
	else return dp[mid][same] = (solve_dp(mid - 1, false) * (k - 2) % mod + solve_dp(mid - 1, true)) % mod;
}

lli solve_all (vector <int> &a) {
	int n = a.size();
	fop (i,1,n) if (a[i] == a[i - 1] && a[i] != -1) return 0;
	vector <int> v;
	lli ans = 1;
	fop (i,0,n) {
		if (a[i] == -1) {
			if (v.size() && v.back() < 0) v.back()--;
			else v.pb(-1);
		} else {
			v.pb(a[i]);
		}
	}
	if (v.size() == 1 && v.back() < 0) return 1ll * k * modpow(k - 1, -v.back() - 1) % mod;
	if (v[0] < 0) ans = ans * modpow(k - 1, -v[0]) % mod;
	if (v.back() < 0) ans = ans * modpow(k - 1, -v.back()) % mod, v.pop_back();
	for (int i = 1; i + 1 < v.size(); i++) if (v[i] < 0) {
		ans = ans * solve_dp(-v[i], v[i + 1] == v[i - 1]) % mod;
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n >> k;
    fop (i,0,N) fop (j,0,2) dp[i][j] = -1;
    dp[1][1] = k - 1;
    dp[1][0] = k - 2;
    vector <int> odd, even;
    fop (i,0,n) {
    	cin >> tmp;
    	if (i & 1) odd.pb(tmp);
    	else even.pb(tmp);
	}
	lli ans = solve_all(odd) * solve_all(even) % mod;
	cout << ans << endl;
}
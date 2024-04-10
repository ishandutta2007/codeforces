#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

int muu(int x) {
	int ans = 1;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			ans *= -1;
			x /= i;
			if (x % i == 0) {
				ans = 0;
				break;
			}
		}
	}
	if (x > 1) ans *= -1;
	return ans;
}

lli M = 2e18;

lli mul(lli a, lli b) {
	if (!b) return 0;
	if (a < M / b) return a * b;
	return M;
}

lli modpow(lli a, int b) {
	lli ans = 1;
	for (; b; b >>= 1, a = mul(a, a)) {
		if (b & 1) ans = mul(ans, a);
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int mu[60];
    fop (i,2,60) mu[i] = muu(i);
    while (t--) {
    	lli n;
    	cin >> n;
    	lli ans = n - 1;
    	lli cur = 0;
    	fop (i,2,10) {
    		cur = powl(n, 1.0 / i);
    		if (modpow(cur + 1, i) <= n) cur++;
    		ans += (cur - 1) * mu[i];
		}
		fop (i,10,60) {
			while (modpow(cur, i) > n) cur--;
			ans += (cur - 1) * mu[i];
		}
		cout << ans << '\n';
	}
}
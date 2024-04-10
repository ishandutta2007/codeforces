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
#define pdd pair<ld,ld> 
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 10000001, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

vector <int> lastPrime (int n) {
	vector <int> ans(n + 1, 0), prime;
	for (int i = 2; i <= n; ++i) {
		if (!ans[i]) {
			prime.push_back(i);
			ans[i] = i;
		}
		for (int j = 0; 1ll * prime[j] * i <= n; j++) {
			ans[prime[j] * i] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n), lp = lastPrime(N);
	fop (i,0,n) cin >> a[i];
	vector <int> ans1(n), ans2(n);
	fop (i,0,n) {
		vector <int> p;
		while (a[i] > 1) {
			int k = lp[a[i]];
			p.pb(k);
			while (a[i] % k == 0) a[i] /= k;
		}
		if (p.size() == 1) ans1[i] = ans2[i] = -1;
		else {
			ans1[i] = p[0];
			ans2[i] = 1;
			fop (j,1,p.size()) {
				ans2[i] *= p[j];
			}
		}
	}
	fop (i,0,n) cout << ans1[i] << " \n"[i == n - 1];
	fop (i,0,n) cout << ans2[i] << " \n"[i == n - 1];
}
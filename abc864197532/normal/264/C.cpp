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
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, a, b;
	cin >> n >> q;
	vector <lli> v(n), c(n);
	fop (i,0,n) cin >> v[i];
	fop (i,0,n) cin >> c[i];
	while (q--) {
		cin >> a >> b;
		vector <lli> dp(N, -1ll << 60);
		int id1 = -1, id2 = -1;
		fop (i,0,n) {
			dp[c[i]] = max({dp[c[i]], dp[c[i]] + v[i] * a, v[i] * b});
			if (id1 == c[i]) {
                                if (id2 != -1) dp[c[i]] = max(dp[c[i]], dp[id2] + v[i] * b);
			} else if (id1 != -1) {
                                dp[c[i]] = max(dp[c[i]], dp[id1] + v[i] * b);
                        }
			if (id1 == -1 or dp[id1] < dp[c[i]]) tie(id1, id2) = mp(c[i], id1);
			else if ((id2 == -1 or dp[id2] < dp[c[i]]) and c[i] != id1) id2 = c[i];
                        //test(dp[1]); test(dp[2]);
                        //test(id1); test(id2);
		}
		dp.pb(0);
		cout << *max_element(all(dp)) << '\n';
	}
}
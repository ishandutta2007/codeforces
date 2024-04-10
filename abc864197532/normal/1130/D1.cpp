#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1000087, logN = 17, K = 500;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	vector <int> pos[n];
	fop (i,0,m) {
		cin >> u >> v, u--, v--;
		pos[u].pb((v - u + n) % n);
	}
	int mx = 0;
	fop (i,0,n) {
		mx = max(mx, int(pos[i].size()));
		sort(rall(pos[i]));
	}
	vector <int> big;
	fop (i,0,n) if (pos[i].size() == mx) big.pb(i);
	fop (i,0,n) {
		int ans = 0;
		fop (j,0,n) {
			fop (k,0,pos[j].size()) {
				ans = max(ans, k * n + pos[j][k] + (j - i + n) % n);
			}
		}
		cout << ans << ' ';
	}
}
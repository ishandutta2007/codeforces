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
const int mod = 998244353, x = 864197532, N = 10, logN = 18, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, tmp;
    cin >> n >> x;
    vector <int> adj[x];
    fop (i,0,n) {
    	cin >> tmp;
    	adj[tmp - 1].pb(i);
	}
	vector <int> pre(x, -1), suf(x, n + 87);
	lli ans = 0;
	fop (i,0,x) {
		if (i) {
			if (pre[i - 1] == n + 87) pre[i] = n + 87;
			else if (adj[i].size()) {
				if (adj[i][0] > pre[i - 1]) pre[i] = adj[i].back();
				else pre[i] = n + 87;
			}
			else pre[i] = pre[i - 1];
		} else {
			if (adj[i].size()) pre[i] = adj[i].back();
		}
		if (pre[i] < n + 87) ans++;
	}
	if (ans < x) ans++;
	FOP (i,x,0) {
		if (i < x - 1) {
			if (suf[i + 1] == -1) suf[i] = -1;
			else if (adj[i].size()) {
				if (adj[i].back() < suf[i + 1]) suf[i] = adj[i][0];
				else suf[i] = -1;
			}
			else suf[i] = suf[i + 1];
		} else {
			if (adj[i].size()) suf[i] = adj[i][0];
		}
	}
	FOP (i,x,0) {
		int k = suf[i];
		if (k == -1) break;
		int p = lower_bound(all(pre), k) - pre.begin();
		if (p < x) p++;
		ans += min(p, i);
	}
	cout << ans << endl;
}
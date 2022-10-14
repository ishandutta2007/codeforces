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

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	vector <vector <int>> adj(n);
	fop (i,0,m) {
	    cin >> u >> v; u--; v--;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	vector <int> a(n);
	vector <int> t, ans;
	fop (i,0,n) {
	    cin >> a[i];
	    if (!a[i]) t.pb(i);
	}
	vector <int> cur(n, 0);
	while (t.size()) {
	    int k = t.back(); t.pop_back();
	    if (cur[k] != a[k]) continue;
	    ans.pb(k + 1);
	    cur[k]++;
	    for (int i : adj[k]) {
	        cur[i]++;
	        if (cur[i] == a[i]) t.pb(i);
	    }
	}
	cout << ans.size() << endl;
	printv(ans);
}
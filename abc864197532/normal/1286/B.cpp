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
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17, K = 350;

vector <int> adj[N];
vector <int> c(N);

int dfs(int v) {
	if (c[v] == 0) return v;
	for (int u : adj[v]) {
		int tmp = dfs(u);
		if (tmp != -1) return tmp;
	}
	return -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, root;
    cin >> n;
    int p[n];
    fop (i,0,n) {
    	cin >> p[i] >> c[i];
		p[i]--;
    	if (p[i] == -1) root = i;
    	else adj[p[i]].pb(i);
	}
	vector <int> ans(n, 0);
	fop (i,1,n + 1) {
		int v = dfs(root);
		if (v == -1) {
			cout << "NO\n";
			return 0;
		}
		ans[v] = i;
		for (int i = v; ~i; i = p[i]) c[i]--;
	}
	cout << "YES\n";
	printv(ans);
}
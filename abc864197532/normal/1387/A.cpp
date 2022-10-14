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
const int mod = 998244353, x = 864197532, N = 100000, logN = 17, K = 350;

vector <pii> adj[N];
vector <pii> val(N, {-x, -x});
vector <vector <pair <pii, int>>> restr;
vector <vector <int>> cc;

void dfs(int v, int pa) {
	cc.back().pb(v);
	for (pii A : adj[v]) if (A.X != pa) {
		if (val[A.X].X == -x) {
			val[A.X] = mp(A.Y - val[v].X, -val[v].Y);
			dfs(A.X, v);
		} else {
			restr.back().pb(mp(mp(val[v].X + val[A.X].X, val[v].Y + val[A.X].Y), A.Y));
		}
	}
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, w;
    cin >> n >> m;
    fop (i,0,m) {
    	cin >> u >> v >> w;
    	u--; v--;
    	adj[u].eb(v, w);
    	adj[v].eb(u, w);
	}
	fop (i,0,n) if (val[i].X == -x) {
		restr.pb({});
		cc.pb({});
		val[i] = {0, 1};
		dfs(i, -1);
	}
	bool is = true;
	int cnt = restr.size();
	vector <int> vv(cnt, -x);
	fop (i,0,cnt) {
		for (auto A : restr[i]) {
			if (A.X.Y == 0) {
				if (A.X.X != A.Y) is = false;
			} else {
				if (A.X.Y < 0) A.X.X = -A.X.X, A.X.Y = -A.X.Y, A.Y = -A.Y; 
				int cur = (A.Y - A.X.X) * (3 - A.X.Y);
				if (vv[i] == -x) vv[i] = cur;
				else if (vv[i] != cur) is = false;
			}
		}
		if (vv[i] == -x) {
			vector <int> tmp;
			for (int j : cc[i]) tmp.pb(val[j].X * (val[j].Y < 0 ? 1 : -1));
			sort(all(tmp));
			vv[i] = tmp[tmp.size() / 2] * 2;
		}
	}
	cout << fixed << setprecision(1);
	if (!is) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		vector <ld> ans(n);
		fop (i,0,cnt) for (int j : cc[i]) ans[j] = val[j].X + (long double)(val[j].Y * vv[i]) / 2;
		printv(ans);
	}
}
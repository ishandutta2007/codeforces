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
const int mod = 998244353, x = 864197532, N = 400000, logN = 17, K = 350;

vector <int> adj[N];
vector <pii> query[N];
vector <lli> cur_ans;
vector <int> depth;

template <typename T>
struct Seg {
	int l, r, m;
	T sum, addTag;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		sum = addTag = 0;
		if (r - l != 1) {
			ch[0] = new Seg <T>(l, m);
			ch[1] = new Seg <T>(m, r);
			pull();
		}
	}
	int size() {return r - l;}
	void pull() {sum = ch[0]->sum + ch[1]->sum;}
	void addValue(T v) {sum += v * size();};
	void push() {
		if (addTag) {
			if (r - l != 1) {
				ch[0]->addValue(addTag);
				ch[0]->addTag += addTag;
				ch[1]->addValue(addTag);
				ch[1]->addTag += addTag;
			}
			addTag = 0;
		}
	}
	void set(int p, T v) {
		if (r - l == 1) {
			sum = v;
		} else {
			push();
			if (p < m) {
				ch[0]->set(p,v); 
			} else {
				ch[1]->set(p,v);
			}
			pull();
		}
	}
	T query(int a, int b) {
		if (a <= l and r <= b) return sum;
		push();
		T ans = 0;
		if (a < m) ans += ch[0]->query(a,b); 
		if (m < b) ans += ch[1]->query(a,b);
		return ans;
	}
	void add(int a, int b, T v) {
		if (a >= b) return;
		if (a <= l and r <= b) {
			addValue(v);
			addTag += v;
		} else {
			push();
			if (a < m) ch[0]->add(a,b,v);
			if (m < b) ch[1]->add(a,b,v);
			pull();
		}
	}
};

Seg <lli> root(0, N);

void dfs(int v = 0, int pa = -1) {
	depth[v] = ~pa ? depth[pa] + 1 : 0;
	for (pii A : query[v]) {
		root.add(depth[v], min(depth[v] + A.X + 1, N), A.Y);
	}
	cur_ans[v] = root.query(depth[v], depth[v] + 1);
	for (int u : adj[v]) if (u != pa) {
		dfs(u, v);
	}
	for (pii A : query[v]) {
		root.add(depth[v], min(depth[v] + A.X + 1, N), -A.Y);
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v, w;
    cin >> n;
    fop (i,0,n - 1) {
    	cin >> u >> v;
    	u--; v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	int q;
	cin >> q;
	while (q--) {
		cin >> u >> v >> w; u--;
		query[u].eb(v, w);
	}
	depth.assign(n, 0);
	cur_ans.assign(n, 0);
	dfs(0, -1);
	printv(cur_ans);
}
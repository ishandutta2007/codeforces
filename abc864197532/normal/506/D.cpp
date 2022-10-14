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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17, K = 350;

struct Dsu {
	int n;
	vector <int> dsu, size, move;
	Dsu (int n): n(n) {
		dsu.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
			size[i] = 1;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		if (dsu[x] == x && size[x] == 1) move.pb(x);
		if (dsu[y] == y && size[y] == 1) move.pb(y);
		if (size[x] < size[y]) swap(x, y);
		dsu[y] = x;
		size[x] += size[y];
		size[y] = 0;
		return true;
	}
	void reset() {
		for (int i : move) {
			dsu[i] = i;
			size[i] = 1;
		}
		move.clear();
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, u, v, c;
    cin >> n >> m;
    vector <pii> edge[m];
    map <pii, int> small_ans;
    vector <Dsu*> big_color;
    fop (i,0,m) {
    	cin >> u >> v >> c;
    	u--; v--; c--;
    	edge[c].eb(u, v);
	}
	Dsu small(n);
	vector <int> tmp[n];
	fop (i,0,m) if (edge[i].size()) {
		if (edge[i].size() <= K) {
			for (pii A : edge[i]) {
				small.Union(A.X, A.Y);
			}
			vector <int> ttmp;
			for (int i : small.move) {
				if (tmp[small.Find(i)].empty()) ttmp.pb(small.Find(i));
				tmp[small.Find(i)].pb(i);
			}
			for (int i : ttmp) {
				fop (j,0,tmp[i].size()) fop (k,j + 1,tmp[i].size()) {
					small_ans[mp(tmp[i][j], tmp[i][k])]++;
					small_ans[mp(tmp[i][k], tmp[i][j])]++;
				}
			}
			for (int i : ttmp) tmp[i].clear();
			small.reset();
		} else {
			big_color.pb(new Dsu(n));
			for (pii A : edge[i]) {
				big_color.back()->Union(A.X, A.Y);
			}
		}
	}
	cin >> q;
	while (q--) {
		cin >> u >> v;
		u--; v--;
		int ans = small_ans[mp(u, v)];
		fop (i,0,big_color.size()) {
			ans += (big_color[i]->Find(u) == big_color[i]->Find(v)); 
		}
		cout << ans << '\n';
	}
}
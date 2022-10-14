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
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17;

int dsu[N];

void Init() {
	fop (i,0,N) dsu[i] = i;
}

int Find(int x) {
	if (dsu[x] == x) return x;
	return dsu[x] = Find(x);
}

void Union(int u, int v) {
	dsu[Find(u)] = Find(v);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m;
	vector <set <int>> tower(m);
	vector <int> ans(m, 0);
	fop (i,0,n) {
		cin >> k; k--;
		tower[k].insert(i);
		if (tower[k].count(i - 1)) ans[k]++;
	}
	int cur_ans = accumulate(all(ans), 0);
	cout << n - 1 - cur_ans << endl;
	Init();
	while (m --> 1) {
		int u, v;
		cin >> u >> v; u--; v--;
		u = Find(u), v = Find(v);
		cur_ans -= (ans[u] + ans[v]);
		if (tower[u].size() < tower[v].size()) swap(tower[u], tower[v]), swap(ans[u], ans[v]); 
		for (int i : tower[v]) {
			tower[u].insert(i);
			if (tower[u].count(i - 1)) ans[u]++;
			if (tower[u].count(i + 1)) ans[u]++;
		}
		tower[v].clear();
		ans[v] = 0;
		Union(v, u);
		cur_ans += ans[u];
		cout << n - 1 - cur_ans << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 5000

vector <pii> nums[MAXN];
vector <pii> line;
vector <int> ans(MAXN, 1);
vector <tuple<int,int,int>> query;

bool dfs1 (int v, int f, int w, int pa) {
	if (v == f) return true;
	for (pii i : nums[v]) {
		if (i.X == pa) continue;
		if (dfs1(i.X, f, w, v)) {
			ans[i.Y] = w;
			return true;
		}
	}
	return false;
}

int dfs2 (int v, int f, int pa) {
	if (v == f) return INT_MAX;
	for (pii i : nums[v]) {
		if (i.X == pa) continue;
		int a = dfs2(i.X, f, v);
		if (a != -1) return min(ans[i.Y], a);
	}
	return -1;
}

int main () {
	int n, a, b, c;
	cin >> n;
	fop (i,0,n-1) {
		cin >> a >> b;
		a--; b--;
		nums[a].pb({b, i});
		nums[b].pb({a, i});
		line.eb(a, b);
	}
	int q;
	cin >> q;
	fop (i,0,q) {
		cin >> a >> b >> c;
		a--, b--;
		query.eb(c, a, b);
	}
	sort(query.begin(), query.end());
	fop (i,0,q) {
		tie(a, b, c) = query[i];
		dfs1(b, c, a, -1);
	}
	bool is = true;
	fop (i,0,q) {
		tie(a, b, c) = query[i];
		if (dfs2(b, c, -1) != a) is = false;
	}
	if (!is) cout << -1 << endl;
	else {
		fop (i,0,n-1) cout << ans[i] << " \n"[i == n - 2];
	}
}
#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define sqr(n) ((n) * (n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef pair<double, int> mp;
typedef long long LL ;
const int maxn = 3e5 + 5;
const double eps = 1e-9;

int par[maxn], siz[maxn], dep[maxn], top[maxn];
int dfn[maxn], idx, mson[maxn], n, m;
vector<int> adj[maxn];
#define add(u, v) adj[u].pb(v)
struct Line {
	double k, b, x1, x2; int man;
	Line(double _k = 0.0, double _b = 0.0, double _x1 = 0.0, double _x2 = 0.0, int _man = 0)
		{k = _k; b = _b; x1 = _x1; x2 = _x2; man = _man;}
};
vector< Line > line[maxn];
vector< pair<double, int> > iss[maxn];
double ans = 1e10;

void dfs1(int u)
{
	siz[u] = 1;
	for (auto v: adj[u])
	if (v != par[u])
	{
		dep[v] = dep[u] + 1; par[v] = u;
		dfs1(v); siz[u] += siz[v];
		if (siz[mson[u]] < siz[v]) mson[u] = v;
	}
}
void dfs2(int u, int tp)
{
	dfn[u] = ++idx; top[u] = tp;
	if (mson[u]) dfs2(mson[u], tp);
	for (auto v: adj[u])
		if (v != par[u] && v != mson[u] ) dfs2(v, v);
}
int lca(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = par[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
void insert(int cate, double x1, double y1, double x2, double y2, int man)
{
	double k, b;
	if (fabs(x1 - x2) < eps) k = 0, b = y1;
	else k = (y2 - y1) / (x2 - x1), b = y1 - x1 * k;
	if (x1 > x2) swap(x1, x2), swap(y1, y2);
	line[cate].pb( Line(k, b, x1, x2, man));
	int i = line[cate].size();
	iss[cate].pb( mp(x1, -i));
	iss[cate].pb( mp(x2, i));
}
void insert(int u, int v, double cur, double vel, int man)
{
	while (top[u] != top[v])
	{
		insert(top[u], cur, dep[u], cur + (dep[u] - dep[top[u]]) * vel, dep[top[u]], man);
		cur += (dep[u] - dep[top[u]]) * vel;
		u = top[u];
		insert(top[u] + n, cur, dep[u], cur + vel, dep[par[u]], man);
		cur += vel;
		u = par[u];
	}
	insert(top[u], cur, dep[u], cur + (dep[u] - dep[v]) * vel, dep[v], man);
}
double f(Line &a, double x)
{
	return a.k * x + a.b;
}
void intersect(Line &a, Line &b)
{
	if (a.man == b.man) return ;
	if (fabs(a.k - b.k) < eps && a.b != b.b) return ;
	
	double x;
	if (fabs(a.k - b.k) < eps) x = max(a.x1, b.x1);
	else x = (b.b - a.b) / (a.k - b.k);
	if (x < a.x1 - eps || x > a.x2 + eps) return ;
	if (x < b.x1 - eps || x > b.x2 + eps) return ;
	ans = min(ans, x);
}

double foo;int bar;
struct SetNode {
	int index;
	SetNode (int _index) {index = _index;}
	bool operator<(const SetNode &v) const
	{
		double f1 = f(line[bar][v.index], foo);
		double f2 = f(line[bar][index], foo);
		return fabs(f1 - f2) > eps ? f1 < f2 : v.index < index;
	}
};
set<SetNode> s;

void solve()
{
	sort(iss[bar].begin(), iss[bar].end());
	s.clear();
	for (auto e: iss[bar])
	{
		int i = e.second;
		foo = e.first;
		int _i = mabs(i) - 1;
		if (e.first > ans - eps) break;
		if (i < 0) {
			auto o = s.insert( SetNode(_i) ).first;
			auto p = o; p--;
			auto q = o; q++;
			if (o != s.begin())
				intersect(line[bar][_i], line[bar][p -> index]);
			if (q != s.end())
				intersect(line[bar][_i], line[bar][q -> index]);
		}
		if (i > 0) {
			auto o = s.find( SetNode(_i) ) ;
			if ( o == s.end()) continue;
			auto p = o; p--;
			auto q = o; q++;
			if (o != s.begin() && q != s.end())
				intersect(line[bar][p -> index], line[bar][q -> index]);
			s.erase(o);
		}
	}
}
int main()
{
	#ifdef FILE_TEST
		freopen("iron.in", "r", stdin);
	#endif
	
	scanf("%d %d", &n, &m);
	for (int u, v, i = 1; i < n ; i++)
		scanf("%d %d", &u, &v), add(u, v), add(v, u);
	dep[1] = 1; dfs1(1); dfs2(1, 1);
	
	for (int t, u, v, c, i = 1; i <= m ; i++)
	{
		scanf("%d %d %d %d", &t, &c, &u, &v);
		int _lca = lca(u, v);
		if (u == v)
			insert(u, _lca, t, 1. / c, i);
		else {
			insert(u, _lca, t, 1. / c, i);
			insert(v, _lca, t + (dep[u] + dep[v] - 2. * dep[_lca]) / c, -1. / c, i);
		}
	}
	for (int i = 1; i <= n * 2; i++)
		if (!line[i].empty()) {bar = i; solve();}
	if (ans > 1e9) printf("-1");
	else printf("%.8lf", ans);
	return 0;
}
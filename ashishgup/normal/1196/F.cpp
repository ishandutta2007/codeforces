#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

typedef struct data
{
	int u, v, w, idx;

	data() {}
 
	data(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
}edge;

struct myStruct
{
	bool operator() (data d1, data d2) const{
		if(d1.w != d2.w)
			return d1.w < d2.w;
		else if(d1.u != d2.u)
			return d1.u < d2.u;
		else
			return d1.v < d2.v;
	}
};

int n, m, k;
vector<pair<int, int> > g[N];
data edges[N];
set<data, myStruct> s;

void add_edge(int idx, int u, int v, int w)
{
	edges[idx]=edge(u, v, w, idx);
}

bool comp(data &d1, data &d2)
{
	return d1.w < d2.w;
}	

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		add_edge(i, x, y, w);
	}
	sort(edges + 1, edges + m + 1, comp);
	for(int i = 1; i <= min(k, m); i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		s.insert(edges[i]);
	}
	map<pair<int, int>, int> m;
	while(m.size() < 2 * k)
	{
		edge cur = *s.begin();
		int u = cur.u;
		int v = cur.v;
		int w = cur.w;
		s.erase(s.begin());
		if(u == v)
			continue;
		if(m.find({u, v}) == m.end())
		{
			m[{u, v}] = w;
			m[{v, u}] = w;
		}
		else
			continue;
		for(auto &it:g[u])
		{
			edge nw;
			nw.u = it.first;
			nw.v = v;
			nw.w = w + it.second;
			s.insert(nw);
		}
		for(auto &it:g[v])
		{
			edge nw;
			nw.u = it.first;
			nw.v = u;
			nw.w = w + it.second;
			s.insert(nw);
		}
	}
	int ans = 0;
	for(auto &it:m)
		ans = max(ans, it.second);
	cout << ans;
	return 0;	
}
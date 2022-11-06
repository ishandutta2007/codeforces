#include<bits/stdc++.h>
using namespace::std;

#define ll long long
#define pb push_back

template<int maxn , int maxm> struct Flow
{
	static const int inf = 1e9;
	int from[maxm * 2] , to[maxm * 2] , head[maxn] , prv[maxm * 2] , id , d[maxn] , pt[maxn];
	int cap[maxm * 2];
 
	Flow()
	{
		memset(from , 0 , sizeof from);
		memset(to , 0 , sizeof to);
		memset(cap , 0 , sizeof cap);
		memset(d , 0 , sizeof d);
		memset(head , -1 , sizeof head);
		id = 0;
	}

	void reset()
	{
		memset(from , 0 , sizeof from);
		memset(to , 0 , sizeof to);
		memset(cap , 0 , sizeof cap);
		memset(d , 0 , sizeof d);
		memset(head , -1 , sizeof head);
		id = 0;
		id = 0;
	}
 
	void add_edge(int v , int u , ll c)
	{
		prv[id] = head[v] , head[v] = id , from[id] = v , to[id] = u , cap[id] = c , id++;
		prv[id] = head[u] , head[u] = id , from[id] = u , to[id] = v , cap[id] = 0 , id++;
	}
 
	bool bfs(int S , int T)
	{
		queue<int> q;
		memset(d , 63 , sizeof d);
		d[S] = 0;
		q.push(S);
 
		memcpy(pt , head , sizeof head);
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
 
			for(int e = head[v]; e != -1; e = prv[e])
				if(cap[e] && d[to[e]] > d[v] + 1)
				{
					d[to[e]] = d[v] + 1;
					q.push(to[e]);
				}
		}
 
		return (d[T] < 1e9);
	}
 
	int dfs(int v , int T , int flow = inf)
	{
		if(v == T || !flow)
			return flow;
 
		ll res = 0;
		for(; pt[v] != -1; pt[v] = prv[pt[v]])
		{
			int e = pt[v] , u = to[e];
 
			if(cap[e] && d[u] == d[v] + 1)
			{
				int x = dfs(u , T , min(flow , cap[e]));
				flow -= x , cap[e] -= x , cap[e ^ 1] += x;
				res += x;
			}
 
			if(!flow)
				break;
		}
 
		return res;
	}
 
	int getFlow(int S , int T)
	{
		int res = 0;
		while(bfs(S , T))
			res += dfs(S , T);
 
		return res;
	}
};
 
const int maxn = 2e4 + 20;
const int maxm = 2e5 + 20;

int from[maxm] , to[maxm] , w[maxm];

int n , m;

Flow<maxn , maxm> F;

bool check(int x)
{
	F.reset();
	int S = n + n , T = S + 1;
	for(int i = 0; i < m; i++)
		if(w[i] <= x)
			F.add_edge(from[i] , to[i] + n , 1);

	for(int i = 0; i < n; i++)
		F.add_edge(S , i , 1);

	for(int i = n; i < n + n; i++)
		F.add_edge(i , T , 1);

	int flow = F.getFlow(S , T);

	return flow == n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<int> cmp;
	cmp.pb(0);
	for(int i = 0; i < m; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;
		a-- , b--;

		from[i] = a , to[i] = b , w[i] = c;
		cmp.pb(w[i]);
	}

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	int l = 0 , r = (int)cmp.size() - 1;
	if(!check(cmp[r]))
		return cout << -1 << endl , 0;

	while(r - l > 1)
	{
		int mid = (l + r) / 2;

		if(check(cmp[mid]))
			r = mid;
		else
			l = mid;
	}

	cout << cmp[r] << endl;
}
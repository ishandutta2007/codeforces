#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e2 + 20;
const int maxm = 1e5 + 20;

template<int maxn , int maxm> struct Flow
{
	static const ll inf = 1e18;
	int from[maxm * 2] , to[maxm * 2] , head[maxn] , prv[maxm * 2] , id , d[maxn] , pt[maxn];
	ll cap[maxm * 2];

	Flow()
	{
		memset(from , 0 , sizeof from);
		memset(to , 0 , sizeof to);
		memset(cap , 0 , sizeof cap);
		memset(d , 0 , sizeof d);
		memset(head , -1 , sizeof head);
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

	ll dfs(int v , int T , ll flow = inf)
	{
		if(v == T || !flow)
			return flow;

		ll res = 0;
		for(; pt[v] != -1; pt[v] = prv[pt[v]])
		{
			int e = pt[v] , u = to[e];

			if(cap[e] && d[u] == d[v] + 1)
			{
				ll x = dfs(u , T , min(flow , cap[e]));
				flow -= x , cap[e] -= x , cap[e ^ 1] += x;
				res += x;
			}

			if(!flow)
				break;
		}

		return res;
	}

	ll maxFlow(int S , int T)
	{
		ll res = 0;
		while(bfs(S , T))
			res += dfs(S , T);

		return res;
	}
};

Flow<maxn * 2 , maxn * maxn + 20> G;
Flow<maxn , maxn * maxn + 20> H;

bool A[maxn][maxn];

int match[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int S = 2 * n , T = S + 1;
	for(int i = 0; i < n; i++)
	{
		int d;
		cin >> d;

		while(d--)
		{
			int v;
			cin >> v;
			v--;

			A[i][v] = 1;
			G.add_edge(i , v + n , 1);
		}
		G.add_edge(S , i , 1);
	}
	for(int i = 0; i < n; i++)
		G.add_edge(i + n , T , 1);
	assert(G.maxFlow(S , T) == n);

	for(int i = 0; i < G.id; i += 2)
		if(G.from[i] != S && G.to[i] != T && !G.cap[i])
			match[G.from[i]] = G.to[i] - n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j && A[i][match[j]])
				H.add_edge(i , j , 1e9);

	S = n , T = S + 1;

	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x *= -1;

		if(x >= 0)
			H.add_edge(S , i , x) , sum += x;
		else
			H.add_edge(i , T , -x);

	//	sum += x;
	}

	cout << -sum + H.maxFlow(S , T) << endl;
}
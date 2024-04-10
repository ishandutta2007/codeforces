#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxN = 25;
const int maxn = maxN * maxN * 4 + 20;
const int maxm = maxn * maxN * maxN + 20;
const int dx[] = {-1 , 1 , 0 , 0};
const int dy[] = {0 , 0 , 1 , -1};

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

	ll getFlow(int S , int T)
	{
		ll res = 0;
		while(bfs(S , T))
			res += dfs(S , T);

		return res;
	}
};

int id[maxN][maxN] , sht[maxn] , x[maxn] , y[maxn] , sp[maxn] , nw;

ll d[maxn][maxn] , n , m , R , B;

string s[maxN];

void bfs(int sx , int sy)
{
	int k = id[sx][sy];
	memset(d[k] , 63 , sizeof d[k]);
	d[k][k] = 0;

	queue<pair<int , int> > q;
	q.push({sx , sy});

	while(!q.empty())
	{
		int x = q.front().first , y = q.front().second;
		q.pop();

		int idv = id[x][y];
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i] , ny = y + dy[i];
			if(0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] == '.')
			{
				int tmp = id[nx][ny];
				if(d[k][tmp] > d[k][idv] + 1)
				{
					d[k][tmp] = d[k][idv] + 1;
					q.push({nx , ny});
				}
			}
		}
	}

}

Flow<maxn , maxm> G;

bool check(ll M , int S , int T)
{
	G.id = 0;
	memset(G.head , -1 , sizeof G.head);
	for(int ind = 0; ind < R + B; ind++)
	{
		int k = id[x[ind]][y[ind]];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(s[i][j] == '.' && d[k][id[i][j]] <= M / sp[ind])
				{
					if(ind < R)
						G.add_edge(sht[ind] , 2 * id[i][j] , 1);
					else
						G.add_edge(2 * id[i][j] + 1 , sht[ind] , 1);
				}

		if(ind < R)
			G.add_edge(S , sht[ind] , 1);
		else
			G.add_edge(sht[ind] , T , 1);
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == '.')
				G.add_edge(2 * id[i][j] , 2 * id[i][j] + 1 , 1);

	return (G.getFlow(S , T) == R);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(id , 63 , sizeof id);

	cin >> n >> m >> R >> B;

	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < m; j++)
			if(s[i][j] == '.')
				id[i][j] = nw++;
	}

	nw *= 2;

	for(int i = 0; i <= R + B; i++)
		cin >> x[i] >> y[i] >> sp[i] , sht[i] = nw++ , x[i]-- , y[i]--;

	if(abs(R - B) != 1)
		return cout << -1 << endl , 0;

	if(R > B)
	{
		swap(x[R] , x[0]);
		swap(y[R] , y[0]);
		swap(sp[R] , sp[0]);
		B++;
	}
	else
		R++;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == '.')
				bfs(i , j);

	int S = nw++ , T = nw++;

	ll l = -1 , r = 1e12;
	if(!check(r , S , T))
		return cout << -1 << endl , 0;

	while(r - l > 1)
	{
		ll M = (l + r) / 2;
		if(check(M , S , T))
			r = M;
		else
			l = M;
	}

	cout << r << endl;
}
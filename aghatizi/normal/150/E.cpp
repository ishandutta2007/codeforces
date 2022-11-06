#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 18;

vector<int> adj[maxn] , ord[maxb];

int sz[maxn] , L , R , edge[maxb][maxn] , h[maxb][maxn] , s[maxn] , seg[maxn * 4];

bool picked[maxn];

int n , from[maxn] , to[maxn] , c[maxn] , w[maxn];

bitset<maxn> is[maxb] , empt[maxb];

void plant(int v , int p = -1)
{
	sz[v] = 1;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u] && u != p)
			plant(u , v) , sz[v] += sz[u];
	}
}

int find_centroid(int v , int n , int p = -1)
{
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u] && u != p && sz[u] * 2 > n)
			return find_centroid(u , n , v);
	}

	return v;
}

void dfs(int v , int lvl , int p = -1)
{
	ord[lvl].pb(v);
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u] && u != p)
		{
			h[lvl][u] = h[lvl][v] + 1;
			edge[lvl][u] = e;
			dfs(u , lvl , v);
		}
	}
}

void decompose(int v , int lvl)
{
	plant(v);
	int n = sz[v];
	v = find_centroid(v , n);
	picked[v] = 1;

	ord[lvl].pb(v);
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u])
		{
			h[lvl][u] = 1;
			edge[lvl][u] = e;
			dfs(u , lvl);
			is[lvl][ord[lvl].back()] = 1;
		}
	}

	ord[lvl].pb(v);
	empt[lvl][v] = 1;

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u])
			decompose(u , lvl + 1);
	}
}

int get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return -maxn;

	int m = (s + e) / 2;

	return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

void update(int p , int val , int s , int e , int v)
{
	while(e - s >= 2)
	{
		seg[v] = max(seg[v] , val);
		
		int m = (s + e) / 2;
		if(p < m)
			e = m , v = 2 * v;
		else
			s = m , v = 2 * v + 1;
	}

	seg[v] = max(seg[v] , val);
}

int ver;

bool check(int x)
{
	for(int i = 0; i < n - 1; i++)
		w[i] = ((c[i] >= x)? 1 : -1);

	for(int lvl = 0; !ord[lvl].empty(); lvl++)
	{
		for(auto v : ord[lvl])
		{
			if(edge[lvl][v] >= 0)
				s[v] = s[from[edge[lvl][v]] ^ to[edge[lvl][v]] ^ v] + w[edge[lvl][v]];
			else
				s[v] = 0;
		}

		for(int i = 0; i < (int)ord[lvl].size(); i++)
		{
			int last = i + 1;
			while(!empt[lvl][ord[lvl][last - 1]])
				last++;

			int m = (last - i + 1);
			fill(seg , seg + 4 * m , -maxn);

			int pt = i;
			for(int j = i; j < last; j++)
			{
				int v = ord[lvl][j];

				if(get(L - h[lvl][v] , R - h[lvl][v] + 1 , 0 , m , 1) + s[v] >= 0)
				{
					ver = v;
					return 1;
				}

				if(is[lvl][v])
					while(pt <= j)
						update(h[lvl][ord[lvl][pt]] , s[ord[lvl][pt]] , 0 , m , 1) , pt++;
			}

			i = last - 1;
		}
	}

	return 0;
}

void handle(int v , int len = 0 , int sum = 0 , int p = -1)
{
	if(L <= len && len <= R && sum >= 0)
	{
		cout << ver + 1 << " " << v + 1 << endl;
		exit(0);
	}

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(u != p)
			handle(u , len + 1 , sum + w[e] , v);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(edge , -1 , sizeof edge);

	cin >> n >> L >> R;

	vector<int> tmp;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b >> c[i];
		a-- , b--;

		tmp.pb(c[i]);
		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	decompose(0 , 0);

	sort(tmp.begin() , tmp.end());
	tmp.resize(unique(tmp.begin() , tmp.end()) - tmp.begin());

	int l = 0 , r = tmp.size();

	while(r - l > 1)
	{
		int m = (l + r) / 2;

		if(check(tmp[m]))
			l = m;
		else
			r = m;
	}

	check(tmp[l]);

	handle(ver);
}
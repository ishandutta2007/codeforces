#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxm = 1e5 + 20;

int cost[maxm] , d[maxn] , res;
int id , par[maxn] , flow , from[maxm] , to[maxm] , cap[maxm];

vector<int> adj[maxn];

bool is_in[maxn];

void add_edge(int a , int b , int c , int val)
{
	adj[a].pb(id);
	from[id] = a , to[id] = b , cost[id] = val , cap[id] = c , id++;
	adj[b].pb(id);
	from[id] = b , to[id] = a , cost[id] = -val , cap[id] = 0 , id++;
}

bool spfa(int S , int T)
{
	queue<int> q;
	memset(d , 63 , sizeof d);
	memset(is_in , 0 , sizeof is_in);

	d[S] = 0;
	q.push(S);
	is_in[S] = 1;

	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		is_in[v] = 0;

		for(auto e : adj[v])
		{
			int u = to[e];

			if(cap[e] > 0 && d[u] > d[v] + cost[e])
			{
				d[u] = d[v] + cost[e];
				par[u] = e;
				if(!is_in[u])
					q.push(u) , is_in[u] = 1;
			}
		}
	}

	if(d[T] < 1e9)
	{
		int mn = 1e9 , tmpT = T;
		while(T != S)
		{
			mn = min(mn , cap[par[T]]);
			T = from[par[T]];
		}

		T = tmpT;
		flow += mn;
		while(T != S)
		{
			cap[par[T]] -= mn , cap[par[T] ^ 1] += mn;
			res += mn * cost[par[T]];
			T = from[par[T]];
		}
		return 1;
	}
	else
		return 0;
}

int b[maxn] , cnt[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	for(auto ch : s)
		cnt[ch - 'a']++;

	for(int i = 0; i < n; i++)
		cin >> b[i];

	int id = n;
	int S = id++ , T = id++;
	for(int ch = 0; ch < 26; ch++)
	{
		int ver = id++;
		add_edge(S , ver , cnt[ch] , 0);
		if(!cnt[ch])
			continue;

		for(int i = 0; i < n / 2; i++)
		{
			int j = n - i - 1;

			int nw = id++;
			add_edge(ver , nw , 1 , 0);
			add_edge(nw , i , 1 , ((s[i] == ch + 'a')? -b[i] : 0));
			add_edge(nw , j , 1 , ((s[j] == ch + 'a')? -b[j] : 0));
		}
	}

	for(int i = 0; i < n; i++)
		add_edge(i , T , 1 , 0);

	while(spfa(S , T));
	cout << -res << endl;
}
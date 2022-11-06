#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxm = 600 + 20;
const int maxn = 1e6 + 20;

int x[maxn] , y[maxn] , L[maxn] , R[maxn] , t[maxn];

int from[maxn] , to[maxn] , head[maxn] , prv[maxn] , id , idx;
ll in[maxn] , out[maxn] , suml , l[maxn] , r[maxn] , cap[maxn] , cost[maxn];

void add_edge(int v , int u , ll c , ll co = 0)
{
	prv[id] = head[v] , head[v] = id , from[id] = v , to[id] = u , cap[id] = c , cost[id] = co , id++;
	prv[id] = head[u] , head[u] = id , from[id] = u , to[id] = v , cap[id] = 0 , cost[id] = -co , id++;
}

void add_edge_lr(int v , int u , ll lx , ll rx)
{
	if(lx > rx)
		cout << -1 << endl , exit(0);

	l[idx] = lx , r[idx] = rx;
	add_edge(v , u , rx - lx);
	suml += lx;
	idx++;
	in[u] += lx;
	out[v] += lx;
}

ll d[maxm] , flow, res , par[maxm];
bool is_in[maxm];

int spfa(int S , int T)
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

		for(int e = head[v]; e != -1; e = prv[e])
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

	if(d[T] < 1e17)
	{
		ll mn = 1e9 , tmpT = T;
		while(T != S)
		{
			mn = min(mn , cap[par[T]]);
			if(cost[par[T]] == 1)
				mn = 1;
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

ll getFlow(int S , int T)
{
	flow = res = 0;
	while(spfa(S , T));
	return flow;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(head , -1 , sizeof head);

	int n1 , n2 , m , R , B;
	cin >> n1 >> n2 >> m >> R >> B;

	string s1 , s2;
	cin >> s1 >> s2;

	int S = n1 + n2 , T = S + 1;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;
		b += n1;

		add_edge(a , b , 1 , R);
		add_edge(b , a , 1 , B);
	}

	for(int i = 0; i < n1; i++)
	{
		char ch = s1[i];
		if(ch == 'U')
		{
			add_edge(S , i , 1e9 , 0);
			add_edge(i , T , 1e9 , 0);
		}

		if(ch == 'R')
			add_edge_lr(S , i , 1 , 1e9);
		if(ch == 'B')
			add_edge_lr(i , T , 1 , 1e9);
	}

	for(int i = n1; i < n1 + n2; i++)
	{
		char ch = s2[i - n1];
		if(ch == 'U')
		{
			add_edge(S , i , 1e9 , 0);
			add_edge(i , T , 1e9 , 0);
		}

		if(ch == 'B')
			add_edge_lr(S , i , 1 , 1e9);
		if(ch == 'R')
			add_edge_lr(i , T , 1 , 1e9);
	}

	add_edge(T , S , 1e16);

	int ss = T + 1 , tt = ss + 1;
	for(int i = 0; i <= T; i++)
	{
		if(in[i])
			add_edge(ss , i , in[i]);
		if(out[i])
			add_edge(i , tt , out[i]);
	}

	if(getFlow(ss , tt) != suml)
		return cout << -1 << endl , 0;

	cout << res << endl;
	for(int i = 0; i < m; i++)
	{
		int x = 2 * i;
		if(!cap[2 * x])
			cout << "R";
		else if(!cap[2 * x + 2])
			cout << "B";
		else
			cout << "U";
	}
	cout << endl;
}
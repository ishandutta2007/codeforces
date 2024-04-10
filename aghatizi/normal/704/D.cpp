#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

int x[maxn] , y[maxn] , L[maxn] , R[maxn] , t[maxn];

int from[maxn] , to[maxn] , head[maxn] , prv[maxn] , pt[maxn] , id , idx;
ll in[maxn] , out[maxn] , suml , l[maxn] , r[maxn] , cap[maxn];

void add_edge(int v , int u , ll c)
{
	prv[id] = head[v] , head[v] = id , from[id] = v , to[id] = u , cap[id] = c , id++;
	prv[id] = head[u] , head[u] = id , from[id] = u , to[id] = v , cap[id] = 0 , id++;
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

int d[maxn] , q[maxn] , lq , rq;

bool bfs(int S , int T)
{
	fill(d , d + T + 1 , 1e9);
	d[S] = lq = rq = 0;
	q[rq++] = S;

	for(int i = 0; i <= T; i++)
		pt[i] = head[i];
	while(lq < rq)
	{
		int v = q[lq++];
		for(int e = head[v]; e != -1; e = prv[e])
		{
			int u = to[e];
			if(cap[e] && d[u] > d[v] + 1)
			{
				d[u] = d[v] + 1;
				q[rq++] = u;
			}
		}
	}

	return d[T] < 1e8;
}

ll dfs(int v , int T , ll flow = 1e18)
{
	if(!flow || v == T)
		return flow;

	ll res = 0;
	for(; pt[v] != -1; pt[v] = prv[pt[v]])
	{
		int e = pt[v] , u = to[e];
		if(d[u] == d[v] + 1 && cap[e])
		{
			ll x = dfs(u , T , min(flow , cap[e]));
			cap[e] -= x , cap[e ^ 1] += x , flow -= x;
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
	{
		ll t = dfs(S , T);
		res += t;
	}

	return res;
}

int flr(int a , int b)
{
	return a / b - (a < 0 && a % b != 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(head , -1 , sizeof head);

	int n , m , rc , bc;
	cin >> n >> m >> rc >> bc;

	vector<int> cmpx , cmpy;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		cmpx.pb(x[i]) , cmpy.pb(y[i]);
	}

	sort(cmpx.begin() , cmpx.end());
	sort(cmpy.begin() , cmpy.end());
	cmpx.resize(unique(cmpx.begin() , cmpx.end()) - cmpx.begin());
	cmpy.resize(unique(cmpy.begin() , cmpy.end()) - cmpy.begin());

	int xs = cmpx.size() , ys = cmpy.size();

	for(int i = 0; i < n; i++)
	{
		x[i] = lower_bound(cmpx.begin() , cmpx.end() , x[i]) - cmpx.begin();
		t[x[i]]++;
		y[i] = lower_bound(cmpy.begin() , cmpy.end() , y[i]) - cmpy.begin();
		t[y[i] + xs]++;
	}

	memset(R , 63 , sizeof R);
	for(int i = 0; i < m; i++)
	{
		int type , lx , d;
		cin >> type >> lx >> d;

		if(type == 1)
		{
			int ind = lower_bound(cmpx.begin() , cmpx.end() , lx) - cmpx.begin();
			if(ind < (int)cmpx.size() && cmpx[ind] == lx)
			{
				R[ind] = min(R[ind] , flr(d + t[ind] , 2));
				L[ind] = max(L[ind] , flr(t[ind] - d + 1 , 2));
			}
		}
		else
		{
			int ind = lower_bound(cmpy.begin() , cmpy.end() , lx) - cmpy.begin();
			if(ind < (int)cmpy.size() && cmpy[ind] == lx)
			{
				ind += xs;
				R[ind] = min(R[ind] , flr(d + t[ind] , 2));
				L[ind] = max(L[ind] , flr(t[ind] - d + 1 , 2));
			}
		}
	}

	for(int i = 0; i < n; i++)
		add_edge_lr(x[i] , y[i] + xs , 0 , 1);

	int S = xs + ys , T = xs + ys + 1;
	for(int i = 0; i < xs; i++)
		add_edge_lr(S , i , L[i] , R[i]);
	for(int i = 0; i < ys; i++)
		add_edge_lr(i + xs , T , L[i + xs] , R[i + xs]);
	add_edge(T , S , 1e18);

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
	getFlow(S , T);
	ll xxx = 0;

	string sht = "rb";
	if(rc < bc)
		sht = "br" , swap(rc , bc);

	string str;
	str.resize(n);
	for(int i = 0; i < n; i++)
	{
		if(cap[i * 2 + 1])
			str[i] = sht[1] , xxx++;
		else
			str[i] = sht[0];
	}
	cout << xxx * bc + (n - xxx) * rc << endl << str << endl;
}
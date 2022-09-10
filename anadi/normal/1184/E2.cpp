#include<bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first 
#define se second

using namespace std;

typedef vector<int> VI;

const int maxn = 1e5 + 7;
const int maxk = 20;

vector<pair<int ,int > > wek[maxn];
int pre[maxn], post[maxn];
int f[maxn][maxk];
int maxi[maxn][maxk];
int F[maxn];

map<pair<int, int>, int> mapa;
int t;
int odp[maxn * 10];

bool czy(int a, int b)
{
	return pre[a] <= pre[b] && post[b] <= post[a];
}

int fin(int x)
{
	if(F[x] != x) F[x] = fin(F[x]);
	return F[x];
}

void uni(int a, int b)
{
	F[fin(a)] = fin(b);
}

void dfs(int x)
{
	pre[x] = t++;
	for(auto s : wek[x])
		if(s.fi != f[x][0])
		{
			f[s.fi][0] = x;
			maxi[s.fi][0] = s.se;
			//cerr << s.fi << " "<< x << s.se <<endl;
			dfs(s.fi);
		}
	post[x] = t++;
}

int ma(int a, int b)
{
	int res = 0;
	int k = maxk - 1;
	while(k >= 0)
	{
		if(!czy(f[a][k], b))
		{
			res = max(maxi[a][k], res);
			a = f[a][k];
		}
		k--;
	}
	if(!czy(a, b))
	{
		res = max(res, maxi[a][0]);
		a = f[a][0];
	}
	k = maxk - 1;
	while(k >= 0)
	{
		if(!czy(f[b][k], a))
		{
			res = max(maxi[b][k], res);
			b = f[b][k];
		}	
		k--;
	}
	if(!czy(b, a))
	{
		res = max(res, maxi[b][0]);
		b = f[b][0];
	}
	return res;	
}

int main()
{
	vector<vector<int> > xd, xdxd;
	int n, m;
	cin>>n>>m;
	for(int i = 1;i <= m;i++)
	{
		odp[i] = -1;
		int a, b, c;
		cin>>a>>b>>c;
		mapa[{a, b}] = i;
		mapa[{b, a}] = i;
		xd.pb({c, a, b});
	}
	sort(all(xd));
	for(int i = 1;i <= n;i++)
		F[i] = i;
	for(auto s : xd)
	{
		if(fin(s[1]) != fin(s[2]))
		{
			wek[s[1]].pb({s[2], s[0]});
			wek[s[2]].pb({s[1], s[0]});
			uni(s[1], s[2]);
		}
		else
			xdxd.pb(s);
	}
	dfs(1);
	f[1][0] = 1;
	for(int k = 1;k < maxk;k++)
		for(int i = 1;i <= n;i++)
		{
			f[i][k] = f[f[i][k - 1]][k - 1];
			maxi[i][k] = max(maxi[i][k - 1], maxi[f[i][k - 1]][k - 1]);
		}	
			
	for(auto s : xdxd)
		odp[mapa[{s[1], s[2]}]] = ma(s[1], s[2]);
	for(int i = 1;i <= m;i++)
		if(odp[i] >= 0)
			cout<<odp[i]<<"\n";
	return 0;
}
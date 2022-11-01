#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define K (60)

ll n,m;
stack <ll> s;
vector <ll> e[N];
pair <ll,ll> last,a[N];

ll par[N][K],dis[N];
bool mark[N];

void dfs(ll x)
{
	mark[x]=1;
	for(int i=1;i<K;i++)
		par[x][i]=par[par[x][i-1]][i-1];
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dis[e[x][i]]=dis[x]+1,par[e[x][i]][0]=x,dfs(e[x][i]);
	mark[x]=0;				
}

ll iPar(ll x,ll num)
{
	for(int i=0;num;i++,num/=2)
		if(num%2)x=par[x][i];
	return x;
}

ll lca(ll x,ll y)
{
	if(dis[x]<dis[y])swap(x,y);
	if(iPar(x,dis[x]-dis[y])==y)return y;
	x=iPar(x,dis[x]-dis[y]);
	for(int i=K-1;i>=0;i--)
		if(par[x][i]!=par[y][i])
			x=par[x][i],y=par[y][i];
	return par[x][0];
}

bool check(ll x,ll y,ll z)
{
	ld m=(ld)(a[x].second-a[y].second)/(a[x].first-a[y].first);
	ld ex=m*(a[z].first-a[x].first)+a[x].second;
	return (ex<a[z].second);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	s.push(n);s.push(n-1);
	e[n-1].push_back(n);e[n].push_back(n-1);
	for(int i=n-2;i>=1;i--)
	{
		while(s.size()>1)
		{
			ll p=s.top();
			s.pop();
			ll q=s.top();
			s.push(p);
			if(!check(i,p,q))break;
			s.pop();
		}
		e[i].push_back(s.top());e[s.top()].push_back(i);
		s.push(i);
	}
	
	dfs(n);
	cin>>m;
	while(m--)
	{
		ll v,u;
		cin>>v>>u;
		cout<<lca(v,u)<<" ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+7)

int n,m;
vector <pair<int,int> > e[N];
ll t[N],d[N];
set <pair<ll,ll> > invlid[N];

ll valid(int x,ll dis)
{
	if(x==n)return dis;
	set <pair<ll,ll> >::iterator it=invlid[x].upper_bound({dis,INF});
	if(it==invlid[x].begin())return dis;
	it--;
	return max(dis,it->second+1); 
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int v,u,w;
		scanf("%d%d%d",&v,&u,&w);
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)scanf("%I64d",&t[j]);
		sort(t,t+k);
		for(int j=0;j<k;j++)
		{
			ll j2=j;
			while(j<k-1 && t[j+1]==t[j]+1)j++;
			invlid[i].insert({t[j2],t[j]});
		}
	}
	set <pair<ll,int> > s;s.insert({valid(1,0),1});d[1]=valid(1,0);
	for(int i=2;i<=n;i++)d[i]=INF;
	while(s.size())
	{
		int x=s.begin()->second;s.erase(s.begin());
		for(int i=0;i<e[x].size();i++)
		{
			ll p=valid(e[x][i].first,d[x]+(ll)e[x][i].second);
			if(p<=d[e[x][i].first])
				s.erase({d[e[x][i].first],e[x][i].first}),d[e[x][i].first]=p,s.insert({d[e[x][i].first],e[x][i].first});
		}
	}
	if(d[n]>=(ll)1e10)printf("-1");
	else printf("%I64d",d[n]);
    return 0;
}
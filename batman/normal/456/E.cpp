#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (301*1000)
#define INF ((ll)1e9)

ll n,m,q,par[N],max_dis,max_dis2,max_id,dis,max_path[N];
bool mark[N],killed[N];
vector <ll> e[N];

ll Par(ll x)
{
	if(par[x]==-1)
		return x;
	return par[x]=Par(par[x]);		
}

void merge(ll x,ll y,bool change=1)
{
	if(Par(x)!=Par(y))
	{
		if(change)max_path[Par(x)]=max((max_path[Par(x)]+1)/2+(max_path[Par(y)]+1)/2+1,max(max_path[Par(x)],max_path[Par(y)]));
		par[Par(y)]=Par(x);
	}
}

void dfs(ll x)
{
	mark[x]=1;
	killed[x]=1;
	dis++;
	if(dis>max_dis)
		max_dis=dis,max_id=x;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dfs(e[x][i]);
	mark[x]=0;
	dis--;	
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)par[i]=-1;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		scanf("%d %d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
		merge(v,u,0);
	}
	for(int i=1;i<=n;i++)
		if(!killed[i])
		{
			max_dis=0;
			dfs(i);
			max_dis=0;
			dfs(max_id);
			max_path[Par(i)]=max_dis-1;
			//cout<<Par(i)<<" "<<max_path[Par(i)]<<"\n";
		}
	while(q--)
	{
		ll ex;
		scanf("%d",&ex);
		if(ex==1)
		{
			ll v;
			scanf("%d",&v);
			printf("%d\n",max_path[Par(v)]);
		}
		else
		{
			ll v,u;
			scanf("%d %d",&v,&u);
			merge(v,u);
			//cout<<max_path[Par(v)]<<" "<<max_path[Par(u)]<<"\n";
		}	
	}	
	
    return 0;
}
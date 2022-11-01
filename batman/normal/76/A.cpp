#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (202)
#define M (51*1000)

struct edge{
	int v,u,s,g;
};

int n,m,g,s,par[N];
ll ans=(ll)2e18;
edge e[M];
set <pair<int,int> > st;

bool gold_(edge a,edge b){return a.g<b.g;}
int root(ll x){if(par[x]<0)return x;return par[x]=root(par[x]);}

int main()
{ 
    scanf("%d%d%d%d",&n,&m,&g,&s);
    for(int i=0;i<m;i++)
    {
    	int v,u,x,y;
    	scanf("%d%d%d%d",&v,&u,&x,&y);
    	if(v==u){i--;m--;continue;}
    	e[i].v=v;e[i].u=u;e[i].g=x;e[i].s=y;
	}
	sort(e,e+m,gold_);
	for(int i=0;i<m;i++)
	{
		st.insert({e[i].s,i});
		for(int j=1;j<=n;j++)par[j]=-1;
		int num=0;
		for(set <pair<int,int> >::iterator it=st.begin();it!=st.end();it++)
		{
			if(root(e[it->second].v)!=root(e[it->second].u))
			{
				num++;
				if(num==n-1){ans=min(ans,(ll)e[i].g*g+(ll)it->first*s);break;}
				par[root(e[it->second].v)]=root(e[it->second].u);
			}
			else
			{
				set <pair<int,int> >::iterator it2=it;it2--;
				pair <ll,ll> ex;ex={it2->first,it2->second};
				st.erase(it);
				it=st.find(ex);
			}
		}	
	}
	if(ans==(ll)2e18)printf("-1");
	else printf("%I64d",ans);
    return 0;
}
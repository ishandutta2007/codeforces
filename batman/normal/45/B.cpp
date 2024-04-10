#include "bits/stdc++.h"
using namespace std;
#define ll int
#define N ((ll)101*1000)

ll n,m,g[N],v[N];
ll par[N],add[N],sz[N];

ll root(ll x){if(par[x]<0)return x;return root(par[x]);}
ll dis(ll x){if(par[x]<0)return add[x];return dis(par[x])+add[x];}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>g[i],par[i]=-i,sz[i]=1;
	for(int i=1;i<=m;i++)cin>>v[i];
	ll res=0;
	for(int i=1;i<=m;i++)
	{
		ll a,b;
		cin>>b;
		a=((v[i]+res-1)%n)+1;
		res=0;
		b-=dis(a);a=-par[root(a)];
		if(a==N)
		{
			cout<<"0\n";
			continue;
		}
		while(b>=1)
		{
			res++;
			ll x=root(a),y=root(g[a]);
			ll d=dis(g[a])+1;
			if(par[y]==-N || x==y){par[x]=-N;break;}
			if(sz[x]<sz[y])
			{
				par[x]=y;
				sz[y]+=sz[x];
				add[x]+=d;add[x]-=add[y];
			}
			else
			{
				par[x]=par[y];par[y]=x;
				sz[x]+=sz[y];
				add[y]-=add[x];add[x]+=d;add[y]-=d;
			}
			a=-par[root(x)];b-=d;
		}
		cout<<res<<"\n";
	}
	return 0;
}
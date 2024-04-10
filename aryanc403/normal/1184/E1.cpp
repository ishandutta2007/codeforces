#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define int long long
#define MIN LLONG_MIN
#define MAX LLONG_MAX
#define PB push_back
#define N 200001
#define MX 262144
#define LG 17
#define M 1000000007
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define LD long double
#define F first
#define S second
#define endl "\n"

/*https://github.com/Ashishgup1/Competitive-Coding/blob/master/DSU%20(Disjoint%20Set%20Union).cpp*/
struct DSU
{
	int connected;
	int par[N], sz[N];

	DSU() {} 

	DSU(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}

	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);

		if(par1==par2)
			return;

		connected--;

		if(sz[par1]>sz[par2])
			swap(par1, par2);

		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};



int32_t main()
{
    LL i,j,lt,z,v,c,r,l,t1,k,h,u,q,ts,te,x,y,n,m,s,b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    vector<pair<LL,pair<LL,LL>>> edge;
    LL sx,sy;
    for(i=1;i<=m;i++)
    {
    	cin>>x>>y>>z;
    	if(i==1)
    	{
    		sx=x;
    		sy=y;
    	}
    	else
    		edge.PB({z,{x,y}});
    }
    sort(edge.begin(),edge.end());
    DSU dsu(n);
    k=1e9;
    for(i=0;i<m-1;i++)
    {
    	x=edge[i].S.F;
    	y=edge[i].S.S;
    	z=edge[i].F;

    	dsu.unite(x,y);
    	if(dsu.getPar(sx)==dsu.getPar(sy))
    	{
    		k=z;
    		break;
    	}
    }
    cout<<k;
}
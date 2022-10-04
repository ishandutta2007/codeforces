#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=200005;

int n,a[MAXN],u[MAXN],v[MAXN];
int gcd(int a,int b)
	{return b?gcd(b,a%b):a;}
vector<int> c[MAXN];
ll f[MAXN];
int x[MAXN],fa[MAXN],size[MAXN];

int getfa(int u)
	{return u==fa[u]?u:fa[u]=getfa(fa[u]);}
inline void merge(int j,int u,int v)
{
	u=getfa(u);v=getfa(v);
	if(u==v)return;
	f[j]+=(ll)size[u]*size[v];
	fa[u]=v;size[v]+=size[u];
}

int mu[MAXN],prm[MAXN],pn;
bool notp[MAXN];
void table(int n)
{
	notp[0]=notp[1]=1;
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!notp[i]){prm[++pn]=i;mu[i]=-1;}
		for(int j=1;j<=pn && prm[j]*i<=n;j++)
		{
			notp[prm[j]*i]=1;
			if(i%prm[j])mu[prm[j]*i]=-mu[i];
			else {mu[prm[j]*i]=0;break;}
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	for(int j=1;j*j<=a[i];j++)
    		if(!(a[i]%j))
			{
				++f[j];
    			if(j*j!=a[i])++f[a[i]/j];
    		}
    }
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&u[i],&v[i]);
    	int t=gcd(a[u[i]],a[v[i]]);
    	for(int j=1;j*j<=t;j++)
    		if(!(t%j))
    		{
    			c[j].pb(i);
    			if(j*j!=t)c[t/j].pb(i);
    		}
    }
    int m=200000;
    for(int i=1;i<=m;i++)
    {
		for(int j=0;j<c[i].size();j++)
		{
			fa[u[c[i][j]]]=u[c[i][j]];size[u[c[i][j]]]=1;
			fa[v[c[i][j]]]=v[c[i][j]];size[v[c[i][j]]]=1;
		}
		for(int j=0;j<c[i].size();j++)
			merge(i,u[c[i][j]],v[c[i][j]]);
	}
    table(m);
    for(int k=1;k<=m;k++)
    {
    	ll ans=0;
    	for(int i=1;i*k<=m;i++)
    		ans+=mu[i]*f[i*k];
    	if(ans)printf("%d %I64d\n",k,ans);
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=15,MOD=998244353;

int n,G[MAXN][MAXN],k,x[MAXN],a[MAXN][MAXN],cnt,s[1<<MAXN],d[1<<MAXN];
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
void gauss(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int t=1ll*a[j][i]*qmi(a[i][i],MOD-2)%MOD;
			for(int k=1;k<=n;k++)
				a[j][k]=(a[j][k]-1ll*t*a[i][k]%MOD+MOD)%MOD;
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    ll ans=0;
    int E,u,v;
    scanf("%d%d%d",&n,&E,&k);
    while(E--)
    {
    	scanf("%d%d",&u,&v);--u;--v;
    	G[u][v]=G[v][u]=1;
    }
    for(int s=0;s<(1<<n);s++)
    {
    	cnt=0;
    	memset(a,0,sizeof(a));
    	for(int i=0;i<n;i++)
    		if(!(s&(1<<i)))x[++cnt]=i;
    	if(!cnt)continue;
    	for(int i=1;i<=cnt;i++)
    		for(int j=1;j<=cnt;j++)
    			if(G[x[i]][x[j]])a[i][j]=-1,++a[i][i];
    	gauss(cnt-1);
    	ll pro=1;
    	for(int i=1;i<=cnt-1;i++)
    		(pro*=a[i][i])%=MOD;
    	for(int i=0;i<n;i++)
    		if(s&(1<<i))
    		{
    			int deg=0;
    			for(int j=0;j<n;j++)
    				if(!(s&(1<<j)) && G[i][j])
    					++deg;
    			pro*=deg;
    		}
    	d[s]=(cnt&1)?pro:-pro;
    }
    for(int i=0;i<(1<<n);i++)
    	for(int j=0;j<(1<<n);j++)
    		if((i&j)==i)s[i]+=d[j];
    for(int i=0;i<(1<<n);i++)
    {
    	int cnt=0;
    	for(int j=0;j<n;j++)
    		if(i&(1<<j))++cnt;
    	if(cnt==k)ans+=s[i];
    }
    cout<<abs(ans)<<endl;
    return 0;
}
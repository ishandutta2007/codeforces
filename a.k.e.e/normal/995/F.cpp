#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define x first
#define y second
const int MAXN=3005,MOD=1000000007;

int n,D;
vector<int> G[MAXN];
int f[MAXN][MAXN];
void dfs(int u)
{
	for(int i=1;i<=n+1;i++)f[u][i]=1;
	for(auto v:G[u])
	{
		dfs(v);
		for(int i=1;i<=n+1;i++)
			f[u][i]=1ll*f[u][i]*f[v][i]%MOD;
	}
	for(int i=1;i<=n+1;i++)
		f[u][i]=(f[u][i]+f[u][i-1])%MOD;
}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
int fac[MAXN],inv[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u;
    scanf("%d%d",&n,&D);
    for(int i=2;i<=n;i++)
    {
    	scanf("%d",&u);
    	G[u].pb(i);
    }
    for(int i=1;i<=n;i++)inv[i]=qmi(i,MOD-2);
    dfs(1);
    int *a=f[1];
    ll ans=0;
    for(int i=1;i<=n+1;i++)
    {
    	ll pro=a[i];
    	for(int j=1;j<=n+1;j++)
    	{
    		if(i==j)continue;
    		if(i<j)pro=pro*(j-D+MOD)%MOD*inv[j-i]%MOD;
    		else pro=pro*(D-j+MOD)%MOD*inv[i-j]%MOD;
    	}
    	ans=(ans+pro)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
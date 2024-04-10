#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=53,MAXT=2505,MOD=1000000007;

int n,T,gt[3][MAXN][MAXN][MAXN],g[MAXN][MAXN][MAXN];
int a[3][MAXN],cnt[3];
int f[MAXN][MAXT],f2[MAXN][MAXN][MAXT];
inline int dmy(int x,int y){x+=y;return x>=MOD?x-MOD:x;}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int ty,x;
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d",&x,&ty);--ty;
    	a[ty][++cnt[ty]]=x;
    }
    gt[0][1][0][0]=gt[1][0][1][0]=gt[2][0][0][1]=g[0][0][1]=g[0][1][0]=g[1][0][0]=1;
    for(int s=2;s<=n;s++)
    	for(int i=0;i<=s;i++)
    		for(int j=0;i+j<=s;j++)
			{
				int k=s-i-j;
				if(i)gt[0][i][j][k]=1ll*i*(gt[1][i-1][j][k]+gt[2][i-1][j][k])%MOD;
				if(j)gt[1][i][j][k]=1ll*j*(gt[0][i][j-1][k]+gt[2][i][j-1][k])%MOD;
				if(k)gt[2][i][j][k]=1ll*k*(gt[0][i][j][k-1]+gt[1][i][j][k-1])%MOD;
				g[i][j][k]=dmy(dmy(gt[0][i][j][k],gt[1][i][j][k]),gt[2][i][j][k]);
			}
	f[0][0]=1;
	for(int i=1;i<=cnt[0];i++)
		for(int x=i;x;x--)
			for(int t=T;t>=a[0][i];t--)
				f[x][t]=dmy(f[x][t],f[x-1][t-a[0][i]]);
	f2[0][0][0]=1;
	for(int i=1;i<=cnt[1];i++)
		for(int x=i;x;x--)
			for(int t=T;t>=a[1][i];t--)
				f2[x][0][t]=dmy(f2[x][0][t],f2[x-1][0][t-a[1][i]]);
	for(int i=1;i<=cnt[2];i++)
		for(int x=0;x<=cnt[1];x++)
			for(int y=i;y;y--)
				for(int t=T;t>=a[2][i];t--)
					f2[x][y][t]=dmy(f2[x][y][t],f2[x][y-1][t-a[2][i]]);
	ll ans=0;
	for(int t=0;t<=T;t++)
		for(int i=0;i<=cnt[0];i++)
			for(int j=0;j<=cnt[1];j++)
				for(int k=0;k<=cnt[2];k++)
					ans=(ans+1ll*f[i][t]*f2[j][k][T-t]%MOD*g[i][j][k])%MOD;
	cout<<ans<<endl;
    return 0;
}
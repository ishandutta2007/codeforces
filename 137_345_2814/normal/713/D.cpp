#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1004
#define M 11
int mx[N][N][M][M],dp[N][N],n,m,q,f[N][N],a,b,c,d;
int rmq(int a,int b,int c,int d)
{
	int s1=0,s2=0;
	while((c-a)>>s1)s1++;
	while((d-b)>>s2)s2++;
	s1--,s2--;
	if(s1==-1)s1++;if(s2==-1)s2++;
	return max(max(mx[a][b][s1][s2],mx[c-(1<<s1)+1][b][s1][s2]),max(mx[a][d-(1<<s2)+1][s1][s2],mx[c-(1<<s1)+1][d-(1<<s2)+1][s1][s2]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&f[i][j]);
		if(f[i][j])dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	mx[i][j][0][0]=dp[i][j];
	for(int k=0;k<=10;k++)
	for(int l=0;l<=10;l++)
	for(int i=1;i+(1<<k)-1<=n;i++)
	for(int j=1;j+(1<<l)-1<=m;j++)
	if(k)
	mx[i][j][k][l]=max(mx[i][j][k-1][l],mx[i+(1<<k-1)][j][k-1][l]);
	else if(l)
	mx[i][j][k][l]=max(mx[i][j][k][l-1],mx[i][j+(1<<l-1)][k][l-1]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int lb=1,rb=min(c-a,d-b)+1,ans=0;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			if(rmq(a+mid-1,b+mid-1,c,d)>=mid)ans=mid,lb=mid+1;
			else rb=mid-1;
		}
		printf("%d\n",ans);
	}
}
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
#define N 305
//n^2,n^3
int dp[N][N][N][2],h[N],r[N],s[N],n,t[N],ct,t2[N],ct2;
map<int,int> l1;
bool cmp(int a,int b){return h[a]<h[b];}
int main()
{
//	freopen("1.txt","w",stdout);
	scanf("%d",&n);
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)scanf("%d%d",&h[i],&r[i]),s[i]=i,t[++ct]=h[i]-r[i],t[++ct]=h[i],t[++ct]=h[i]+r[i];
	sort(s+1,s+n+1,cmp);sort(t+1,t+ct+1);
	t[0]=-1e9;
	for(int i=1;i<=ct;i++)if(t[i]!=t[i-1])t2[++ct2]=t[i],l1[t[i]]=ct2;
	int q1=s[1],lb=l1[h[q1]-r[q1]],md=l1[h[q1]],rb=l1[h[q1]+r[q1]];
	for(int i=1;i<=ct2;i++)
	if(i<=md)
	{
		if(i<lb)dp[2][i][md][0]=t2[md]-t2[i],dp[2][i][rb][0]=t2[rb]-t2[i];
		else if(i<md)dp[2][i][md][1]=t2[md]-t2[i],dp[2][i][rb][0]=t2[rb]-t2[i];
		else dp[2][i][md][1]=t2[md]-t2[i],dp[2][i][rb][1]=t2[rb]-t2[i];
	}
	for(int i=2;i<=n;i++)
	{
		int q1=s[i],lb=l1[h[q1]-r[q1]],md=l1[h[q1]],rb=l1[h[q1]+r[q1]];
		for(int j=1;j<=md;j++)
		for(int k=j;k<=ct2;k++)
		for(int l=0;l<=1;l++)
		if(dp[i][j][k][l]>=0)
		{
		//	printf("%d %d %d %d %d\n",i,j,k,l,dp[i][j][k][l]);
			int nj=j,nk=k,nl=l,as=dp[i][j][k][l];
			if(lb<=j)nl=1;
			if(nl==0&&lb>nk)as+=t2[lb]-t2[nk];
			if(nk<md)as+=t2[md]-t2[max(lb,nk)],nk=md;
			if(nl==1)
			{
				int tp=l1[h[s[i+1]]];
				for(int s=nk+1;s<=tp;s++)
				dp[i+1][s][tp][0]=max(dp[i+1][s][tp][0],as+t2[tp]-t2[s]);
				for(int s=k;s<=lb;s++)
				dp[i+1][s][nk][0]=max(dp[i+1][s][nk][0],as+t2[lb]-t2[s]);
			}
			dp[i+1][nj][nk][nl]=max(dp[i+1][nj][nk][nl],as);
			nj=j,nk=k,nl=l,as=dp[i][j][k][l];
			if(j==md)nl=1;
			if(nl==0&&md>nk)as+=t2[md]-t2[nk];
			if(nk<rb)as+=t2[rb]-t2[max(md,nk)],nk=rb;
			if(nl==1)
			{
				int tp=l1[h[s[i+1]]];
				for(int s=nk+1;s<=tp;s++)
				dp[i+1][s][tp][0]=max(dp[i+1][s][tp][0],as+t2[tp]-t2[s]);
				for(int s=k;s<=md;s++)
				dp[i+1][s][nk][0]=max(dp[i+1][s][nk][0],as+t2[md]-t2[s]);
			}
			dp[i+1][nj][nk][nl]=max(dp[i+1][nj][nk][nl],as);
		}
	}
	int as=0;
	for(int i=1;i<=ct2;i++)
	for(int j=i;j<=ct2;j++)
	as=max(as,dp[n+1][i][j][1]);
	printf("%d\n",as);
}
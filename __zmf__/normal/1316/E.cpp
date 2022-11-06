//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e5+9,K=(1<<7)+9,INF=-1e18;
int n,p,k;
int dp[N][K],a[N][9],q[K];
struct point
{
	int x,val;
}pp[N];
inline bool cmp(point xxx,point yyy)
{
	return xxx.val>yyy.val;
}
signed main()
{
	n=read(),p=read(),k=read();
	for(int i=1;i<=n;i++)pp[i].val=read(),pp[i].x=i;
	sort(pp+1,pp+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p;j++)
			a[i][j]=read();
	for(int i=0;i<(1<<p);i++)
		for(int j=0;j<p;j++)
			if((i&(1<<j))!=0)q[i]++;
	for(int i=0;i<=n;i++)
		for(int j=0;j<(1<<p);j++)
			dp[i][j]=INF;
	dp[0][0]=0;	
	for(int i=1;i<=n;i++)
		for(int j=0;j<(1<<p);j++)
		{
			//cout<<j<<" "<<q[j]<<"-----------"<<endl;
			if(q[j]+k>=i)dp[i][j]=max(dp[i][j],dp[i-1][j]+pp[i].val);
			else dp[i][j]=max(dp[i][j],dp[i-1][j]);
			for(int l=0;l<p;l++)
				if((j&(1<<l))==0)
				{
					dp[i][(j|(1<<l))]=max(dp[i][(j|(1<<l))],dp[i-1][j]+a[pp[i].x][l+1]);
	//				cout<<i<<" "<<j<<" "<<dp[i-1][j]<<"---"<<endl;
				}
		}
	
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i][(1<<p)-1]);
	cout<<ans<<endl;
	return 0;
}
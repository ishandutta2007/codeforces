#include<cstdio>
#include<algorithm>
using namespace std;
#define N 2050
#define ll long long
int n,l[N],r[N],v[N],k;
ll s1[N][N],tp[N][N],dp[N][2];
void doit(int s)
{
	int ti=0;
	ll nw=k,t1=0,fg=0;
	for(int i=s;i<=n;i++)
	{
		if(ti<l[i])ti=l[i];
		if(nw>=v[i])nw-=v[i],t1+=v[i];
		else
		{
			int tp=v[i]-nw;t1+=nw;
			int f1=(tp-1)/k;t1+=tp,ti+=f1+1,nw=k-(tp-1)%k-1;
		}
		if(r[i]<ti)fg=1;
		if(fg){s1[s][i]=1e18;continue;}
		if(i!=n)s1[s][i]=t1+nw,tp[s][i]=ti==r[i];
		else s1[s][i]=t1,tp[s][i]=ti==r[i];
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&l[i],&r[i],&v[i]);
	for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=1e18;
	for(int i=0;i<n;i++)
	{
		doit(i+1);
		for(int j=i+1;j<=n;j++)
		{
			ll f1=r[i]==l[i+1]?dp[i][0]:min(dp[i][0],dp[i][1]);
			dp[j][tp[i+1][j]]=min(dp[j][tp[i+1][j]],f1+s1[i+1][j]);
		}
	}
	ll as=min(dp[n][0],dp[n][1]);
	if(as>1e17)printf("-1\n");
	else printf("%lld\n",as);
}
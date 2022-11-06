//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=(1<<24)+9,INF=1e9;
int sx,sy;
int n;
bool vis[29];
int x[29],y[29];
int dp[N],px[N],py[N];
int val[29][29],sum;
inline int Val(int a,int b)
{
	return 2*x[a]*x[b]+2*y[a]*y[b];
}
int main()
{
	sx=read(),sy=read();
	n=read();
	for(int i=1;i<=n;i++)x[i]=read()-sx,y[i]=read()-sy,sum=sum+2*(x[i]*x[i]+y[i]*y[i]);
	for(int i=0;i<(1<<n);i++)dp[i]=-INF;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			val[i][j]=Val(i+1,j+1);
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
//		cout<<dp[i]<<endl;
		if(dp[i]==-INF)continue;
		for(int j=0;j<n;j++)
		{
			if((i&(1<<j))==0)
			{
			//	cout<<"zhouakngyang txdy!"<<endl;
			//	if(dp[i|(1<<j)]>dp[i]+val[j][j])dp[i|(1<<j)]=dp[i]+val[j][j],px[i|(1<<j)]=j,py[i|(1<<j)]=-1;
				for(int k=0;k<j;k++)
					if((i&(1<<k))==0)
					{
			//			cout<<"zhouakngyang txdy!"<<" "<<i<<" "<<dp[i]<<" "<<j<<" "<<k<<endl;
						if(dp[i|(1<<j)|(1<<k)]<dp[i]+val[j][k])dp[i|(1<<j)|(1<<k)]=dp[i]+val[j][k],px[i|(1<<j)|(1<<k)]=j,py[i|(1<<j)|(1<<k)]=k;
					}
			}
		}
	}
	int ans=0,pos=0;
	for(int i=0;i<(1<<n);i++)
		if(dp[i]>ans)ans=dp[i],pos=i;
//	cout<<ans<<endl;
	printf("%lld\n",sum-ans);
	int now=pos;
	while(now!=0)
	{
	//	cout<<now<<" "<<px[now]<<" "<<py[now]<<endl;
		printf("0 %d ",px[now]+1);
		printf("%d ",py[now]+1);
		vis[px[now]+1]=1,vis[py[now]+1]=1;
		now=now^(1<<px[now])^(1<<py[now]);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])printf("0 %d ",i);
	puts("0");
	return 0;
}
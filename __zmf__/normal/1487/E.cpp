#include<bits/stdc++.h>
using namespace std;
#define int long long
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=150009,M=200009;
bool c[N];
long long m,n[5],a[5][N];
long long ans,dp[5][N];
struct point
{
	int x,y;
}p[M+9];
struct node
{
	int id;long long v;
}q[M+9];
inline bool cmp(node xxx,node yyy)
{
	return xxx.v<yyy.v;
}
inline bool Cmp(point xxx,point yyy)
{
	return xxx.y<yyy.y;
}
signed main()
{
	for(int i=1;i<=4;i++)n[i]=read();
	for(int i=1;i<=4;i++)
		for(int j=1;j<=n[i];j++)
			a[i][j]=read();
	for(int j=1;j<=n[1];j++)dp[1][j]=a[1][j];
	for(int i=2;i<=4;i++)
	{
		for(int j=1;j<=n[i-1];j++)q[j].id=j,q[j].v=dp[i-1][j];
		sort(q+1,q+n[i-1]+1,cmp);
		m=read();
		if(m==n[i]*n[i-1])
		{
			cout<<-1<<endl;
			return 0;
		}
		for(int j=1;j<=m;j++)p[j].x=read(),p[j].y=read();
		sort(p+1,p+m+1,Cmp);
		int now=0,last=1;
		for(int j=1;j<=n[i];j++)
		{
			dp[i][j]=1e10;
			while(p[now+1].y==j&&now<m)
			{
				now++;c[p[now].x]=1;
			}
			for(int k=1;k<=n[i-1];k++)
				if(c[q[k].id]==0)
				{
					dp[i][j]=q[k].v+a[i][j];
					break;
				}
			//cout<<last<<" "<<now<<endl;
			for(int k=last;k<=now;k++)c[p[k].x]=0;
			last=now+1;
		}
	}
	/*for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=n[i];j++)cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	ans=1e10;
	for(int j=1;j<=n[4];j++)ans=min(ans,dp[4][j]);
	if(ans>=1e10)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
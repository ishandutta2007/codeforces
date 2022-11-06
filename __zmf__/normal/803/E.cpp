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
int n,k,flag,b[1009];
char a[1009],ans[1009];
bool dp[1018][2099];//L=-1 W=+1
inline void dfs(int u,int res)
{
	if(u==1)
	{
		if(res==1010)putchar('W');
		else if(res==1009)putchar('D');
		else putchar('L');
		return ;
	}
	if(b[u]==2)
	{
		if(dp[u-1][res+1]==1)
		{
			dfs(u-1,res+1);putchar('L');
		}
		else if(dp[u-1][res]==1)
		{
			dfs(u-1,res);putchar('D');
		}
		else 
		{
			dfs(u-1,res-1);putchar('W');
		}
		return ;
	}
	else 
	{
		
		dfs(u-1,res-b[u]);
		if(a[u]=='W')putchar('W');
		if(a[u]=='D')putchar('D');
		if(a[u]=='L')putchar('L');
		return ;
	}
}
int main()
{
	n=read(),k=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='L')b[i]=-1;
		else if(a[i]=='W')b[i]=1;
		else if(a[i]=='D')b[i]=0;
		else b[i]=2;
	}
	dp[0][1009]=1;
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		if(i==n)flag=1;
		if(b[i]<=1)
		{
			for(int j=1009-k-flag+1;j<1009+k+flag;j++)
				if(dp[i-1][j-b[i]]==1)
				{
					dp[i][j]=1;
			//		cout<<i<<" "<<j<<endl;
				}
		}
		else 
		{
			for(int j=1009-k-flag+1;j<1009+k+flag;j++)
			{
			//	cout<<i<<" "<<j<<"------"<<endl;
				if(dp[i-1][j-1]==1)dp[i][j]=1;
				if(dp[i-1][j]==1)dp[i][j]=1;
				if(dp[i-1][j+1]==1)dp[i][j]=1;
			//	if(dp[i][j])cout<<i<<" "<<j<<endl;
			}
		}
	}
	if(dp[n][1009+k]==1)
	{
		dfs(n,1009+k);
		cout<<ans<<endl;
		return 0;
	}
	else if(dp[n][1009-k]==1)
	{
		dfs(n,1009-k);
		cout<<ans<<endl;
		return 0;
	}
	puts("NO");
	return 0;
}
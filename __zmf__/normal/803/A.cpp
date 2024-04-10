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
int n,k,ans[109][109];
signed main()
{
	n=read();k=read();	
	if(n*n<k)
	{
		puts("-1");return 0;
	}
	if(n==1)
	{
		if(k>1)puts("-1");
		else if(k==1)puts("1");
		else puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(ans[i][j]==1)continue;
			if(i==j&&k>=1)ans[i][j]=1,k--;
			else if(k>=2)ans[i][j]=ans[j][i]=1,k-=2;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}
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
const int N=5e4+9;
int taxi,n,m,sumh[N],sums[N],ans,flag;
char s[N];
vector<int> a[N]; 
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),m=read();ans=1e9+7;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			a[i].push_back(0);
			for(int j=0;j<m;j++)
				if(s[j]=='.')a[i].push_back(0);
				else a[i].push_back(1);
		}
		for(int i=1;i<=n;i++)sumh[i]=0;
		for(int i=1;i<=m;i++)sums[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]==1)sumh[i]++,sums[j]++;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				flag=sumh[i]+sums[j];flag=n+m-1-flag;
				if(a[i][j]==1)flag++;
				ans=min(ans,flag);
			}
		printf("%d\n",ans);
	}
	return 0;
}
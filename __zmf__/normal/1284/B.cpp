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
int n,x,y,ans;
vector<int> G[100009];
int a[100009],cnt,mx[100009],mi[100009];
bool vis[100009];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)mi[i]=1e9+7;
	for(int i=1;i<=n;i++)
	{
		x=read();
		for(int j=1;j<=x;j++)
		{
			y=read();G[i].push_back(y);
			mi[i]=min(mi[i],y),mx[i]=max(mx[i],y);
		}
		for(int j=1;j<x;j++)
			if(G[i][j]>G[i][j-1])vis[i]=1;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])a[++cnt]=mx[i];
	sort(a+1,a+cnt+1);
	//for(int i=1;i<=cnt;i++)cout<<a[i]<<" ";cout<<endl;ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
		//	cout<<mi[i]<<endl;
			int pos=upper_bound(a+1,a+cnt+1,mi[i])-a;
		//	cout<<pos<<endl;
			ans=ans+pos-1;
		//	cout<<ans<<endl;
		}
	ans=n*n-ans;
	cout<<ans<<endl;
	return 0;
}
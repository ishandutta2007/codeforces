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
int n,k,a[109],vis[109];
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k)break;
		else vis[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]>k)break;
		else vis[i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(vis[i]==1)ans++;
	cout<<ans<<endl;
	return 0;
}
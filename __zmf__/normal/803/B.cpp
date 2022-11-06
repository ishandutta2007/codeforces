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
int n,a[200009],dis[200009],now;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)dis[i]=1e9+7;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			dis[i]=0;now=i-1;
			while(a[now]!=0&&now>0)dis[now]=min(dis[now],i-now),now--;
			now=i+1;
			while(a[now]!=0&&now<=n)dis[now]=min(dis[now],now-i),now++;
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
	puts("");
	return 0;
}
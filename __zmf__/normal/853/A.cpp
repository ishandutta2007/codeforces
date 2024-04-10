//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n,k,now,ans[300009],vis[600009];
struct point
{
	int cos,pos;
}p[300009];
inline bool cmp(point xxx,point yyy)
{
	return xxx.cos>yyy.cos;
}
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)p[i].cos=read(),p[i].pos=i;
	sort(p+1,p+n+1,cmp);now=k+1;
	for(int i=1;i<=n;i++)
	{
		if(p[i].pos>now)
		{
			int po=p[i].pos;
			while(vis[po])po++;
			ans[p[i].pos]=po;vis[po]=1;
		}
		else
		{
			ans[p[i].pos]=now;now++;
			while(vis[now])now++;
		}
	}
	long long res=0;
	for(int i=1;i<=n;i++)res=res+(ans[p[i].pos]-p[i].pos)*p[i].cos;
	cout<<res<<endl;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);cout<<endl;
	return 0;
}
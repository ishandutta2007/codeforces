#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int cnt[6]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1,x;i<=n;++i)read(x),++cnt[x];
	for(int i=1,x;i<=n;++i)read(x),--cnt[x];
	for(int i=1;i<=5;++i)
	{
		if(abs(cnt[i])&1)return 0&puts("-1");
		ans+=abs(cnt[i]);
	}
	return 0&printf("%d",ans/4);
}
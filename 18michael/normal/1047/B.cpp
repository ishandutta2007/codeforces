#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
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
	for(int i=1,x,y;i<=n;++i)read(x),read(y),ans=max(ans,x+y);
	printf("%d",ans);
	return 0;
}
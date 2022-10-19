#include<bits/stdc++.h>
using namespace std;
int n,d,e,ans;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(d),read(e),e*=5,ans=n;
	for(int i=0;i*d<=n;++i)ans=min(ans,(n-i*d)%e);
	return 0&printf("%d",ans);
}
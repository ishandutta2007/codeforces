#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,t,Test_num;
LL mx,ans;
LL a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ans=t=mx=0;
		for(int i=1;i<=n;++i)
		{
			read(a[i]);
			while(!(a[i]&1))++t,a[i]>>=1;
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=n;++i)ans+=a[i];
		ans-=mx,ans+=mx<<t,printf("%lld\n",ans);
	}
	return 0;
}
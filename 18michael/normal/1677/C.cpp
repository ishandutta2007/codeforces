#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num,t;LL ans;
int a[100002],b[100002],rt[100002],siz[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),t=ans=0;
		for(int i=1;i<=n;++i)read(a[i]),rt[i]=i,siz[i]=1;
		for(int i=1;i<=n;++i)
		{
			read(b[i]),getroot(a[i]),getroot(b[i]);
			if(rt[a[i]]^rt[b[i]])siz[rt[b[i]]]+=siz[rt[a[i]]],rt[rt[a[i]]]=rt[b[i]];
		}
		for(int i=1;i<=n;++i)
		{
			getroot(i);
			if(rt[i]==i)t+=(siz[i]>>1);
		}
		for(int i=1;i<=t;++i)ans-=i;
		for(int i=n;i>n-t;--i)ans+=i;
		printf("%lld\n",(ans<<1));
	}
	return 0;
}
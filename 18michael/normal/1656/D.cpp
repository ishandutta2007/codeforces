#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include<bits/stdc++.h>
#define Mx 1000000
#define LL long long
using namespace std;
int Test_num,p_t=0;
LL n,t;
LL p[1000002];
bool u[1000002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
inline bool check(LL n)
{
	for(int i=2;p[i]*(p[i]+1)/2<=n;++i)
		if(!(n%p[i]))
		{
			printf("%lld\n",p[i]);
			return 1;
		}
	return 0;
}
int main()
{
	init(),read(Test_num);
	while(Test_num--)
	{
		read(n);
		for(t=1;!((n/t)&1);t<<=1);
		if(2*t>1 && (2*t+1)<=n/t)
		{
			printf("%lld\n",2*t);
			continue;
		}
		if(n/t>1 && (n/t)+1<=t*2)
		{
			printf("%lld\n",n/t);
			continue;
		}
		if(!check(n/t))puts("-1");
	}
	return 0;
}
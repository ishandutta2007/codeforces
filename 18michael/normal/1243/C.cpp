#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,n1,t;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
int main()
{
	read(n),n1=t=n;
	for(LL i=2;i*i<=n1;++i)
		if(!(n1%i))
		{
			t=gcd(t,i);
			do n1/=i;while(!(n1%i));
		}
	if(n1>1)t=gcd(t,n1);
	return 0&printf("%lld",t);
}
#include<cstdio>
#define LL long long
#define mod 1000000007
int n,k,Test_num;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL pow(LL a,int b)
{
	LL c=1;
	for(int i=b;i;i>>=1)
	{
		if(i&1)c=(c*a)%mod;
		a=(a*a)%mod;
	}
	return c;
}
int main()
{
	read(n),read(k),printf("%lld",(pow(k,k-1)*pow(n-k,n-k))%mod);
	return 0;
}
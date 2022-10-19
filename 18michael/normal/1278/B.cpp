#include<cstdio>
#include<cmath>
#define LL long long
int Test_num;
LL a,b,c,d,e,ans;
bool f;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL abs(LL x)
{
	return x<0? -x:x;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		scanf("%lld%lld",&a,&b),c=abs(a-b),d=1+8*c,e=sqrt(d),f=(c&1),ans=e-1;
		if(e*e!=d)++ans;if(ans&1)++ans;ans>>=1;
		while((((ans*(ans+1))>>1)&1)!=f)++ans;
		printf("%lld\n",ans);
	}
	return 0;
}
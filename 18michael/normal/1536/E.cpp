#include<cstdio>
#define LL long long
#define mod 1000000007
int n,m,t,Test_num;
char s[2002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),t=0;
		for(int i=0;i<n;++i)
		{
			scanf("%s",s);
			for(int j=0;j<m;++j)t+=(s[j]=='#');
		}
		printf("%lld\n",(Pow(2,t)+mod-(t==n*m))%mod);
	}
	return 0;
}
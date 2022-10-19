#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
#define Mx 200000
using namespace std;
int n,Test_num,t,cnt,la;
LL ans;
char s[100002];
LL fac[200002],inv[200002];
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
inline void init()
{
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	if(a<b)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),read(Test_num);
	while(Test_num--)
	{
		read(n),scanf("%s",s),ans=1,t=cnt=0;
		for(int i=0;i<n;++i)cnt+=(s[i]=='0');
		for(int i=1;i<n;++i)if(s[i]=='1' && s[i-1]=='1')s[i]=s[i-1]='0',++t;
		++cnt,printf("%lld\n",C(t+cnt-1,cnt-1));
	}
	return 0;
}
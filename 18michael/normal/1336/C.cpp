#include<cstdio>
#include<cstring>
#define mod 998244353
int ls,lt,ans=0;
char s[3002],t[3002];
int f[3002][3002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	scanf("%s%s",s+1,t+1),ls=strlen(s+1),lt=strlen(t+1);
	for(int i=1;i<=ls;++i)f[i][i]=2*(i>lt || s[1]==t[i]);
	for(int l=1;l<ls;++l)
		for(int i=1;i+l<=ls;++i)
			f[i][i+l]=(f[i+1][i+l]*(i>lt || s[l+1]==t[i])+f[i][i+l-1]*(i+l>lt || s[l+1]==t[i+l]))%mod;
	for(int i=lt;i<=ls;++i)ans=(ans+f[1][i])%mod;
	return 0&printf("%d",ans);
}
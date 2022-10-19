#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,l,tot=0,ok=0;
int mod[5]={19260817,998244353,998244853,1000000007,1000000009},a[100002];
char s[12];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL f(LL x,LL mod)
{
	LL res=0;
	for(int i=n;i;--i)res=((res+a[i])*x)%mod;
	return (res+a[0])%mod;
}
inline bool check()
{
	for(int i=0;i<4;++i)if(f(k,mod[i]))return 0;
	return 1;
}
int main()
{
	read(n),read(k);
	for(int i=0,j,f;i<=n;++i)
	{
		scanf("%s",s+1),l=strlen(s+1);
		if(s[1]=='?')
		{
			++tot;
			if(!i)ok=1;
		}
		else
		{
			j=1,f=1;if(s[1]=='-')++j,f=-1;
			while(j<=l)a[i]=a[i]*10+(s[j]^48),++j;
			a[i]*=f;
		}
	}
	return 0&printf(((!k && ((ok && ((n+1-tot)&1)) || (!ok && !a[0]))) || (k && ((tot && (n&1)) || (!tot && check()))))? "Yes":"No");
}
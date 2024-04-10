#include<cstdio>
#define LL long long
#define mod 998244353
int n,n2,tot=0,tot1=0;LL res=1;
bool ok0=1,ok1=1;
LL fac[200002],inv[200002];
char s[100002][2];
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
	fac[0]=1;for(int i=1;i<=n2;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[n2]=Pow(fac[n2],mod-2);for(int i=n2;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	scanf("%d",&n),n2=(n<<1),init();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]);
		if((s[i][0]=='W' && s[i][1]=='W') || (s[i][0]=='B' && s[i][1]=='B'))res=0;
		else if(s[i][0]=='?' && s[i][1]=='?')res=(res<<1)%mod;
		for(int j=0;j<2;++j)tot+=(s[i][j]=='W'),tot1+=(s[i][j]=='?');
		if(s[i][0]=='W' || s[i][1]=='B')ok0=0;
		if(s[i][0]=='B' || s[i][1]=='W')ok1=0;
	}
	if(tot>n || tot+tot1<n)return 0&puts("0");
	return 0&printf("%lld",(C(tot1,n-tot)-res+ok0+ok1+mod)%mod);
}
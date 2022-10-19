#include<cstdio>
#define LL long long
#define mod 1000000009
int n,k;
LL a,b,t,t1,r,ans=0;
char s[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	read(n),read(a),read(b),read(k),t=(pow(a,mod-2)*b)%mod,t1=pow(t,k),r=pow(a,n),scanf("%s",s);
	for(int i=0;i<k;++i)ans=(ans+(s[i]=='+'? 1:-1)*r)%mod,r=(r*t)%mod;
	if(t1==1)t=(n+1)/k;else t=((pow(t,n+1)-1)*pow(t1-1,mod-2))%mod;
	ans=(ans*t)%mod,printf("%lld",(ans+mod)%mod);
	return 0;
}
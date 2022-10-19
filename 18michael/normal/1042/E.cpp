#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,m,tot,r,c,t=0,s;
LL ans=0,res,res1,res2,res3;
int rk[1000002];
LL sum[4];
struct aaa
{
	int val,x,y;
}a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.val<b.val? 1:0;
}
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
inline LL pw(LL x)
{
	return (x*x)%mod;
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
	read(n),read(m),tot=num(n,m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(a[num(i,j)].val),a[num(i,j)].x=i,a[num(i,j)].y=j;
	sort(a+1,a+tot+1,cmp),read(r),read(c);
	for(int i=1;i<=tot;++i)
	{
		while(a[t+1].val<a[i].val)++t;
		rk[i]=t;if(a[i].x==r && a[i].y==c)s=i;
	}
	while(s>1 && a[s-1].val==a[s].val)swap(a[s-1],a[s]),--s;
	for(int i=s,j;i;i=j)
	{
		for(j=i,res=res1=res2=0;j && a[j].val==a[i].val;--j)res=(res+pw(a[j].x)+pw(a[j].y))%mod,res1=(res1+a[j].x)%mod,res2=(res2+a[j].y)%mod;
		ans=(ans+((sum[0]*res)%mod)-((2*sum[1]*res1)%mod)-((2*sum[2]*res2)%mod)+((sum[3]*(i-j))%mod))%mod;
		res3=((sum[0]+(i==s? 1:0))*Pow(rk[i],mod-2))%mod;
		sum[0]=(sum[0]+res3*(i-j))%mod;
		sum[1]=(sum[1]+res3*res1)%mod;
		sum[2]=(sum[2]+res3*res2)%mod;
		sum[3]=(sum[3]+res3*res)%mod;
	}
	return 0&printf("%lld",(ans+mod)%mod);
}
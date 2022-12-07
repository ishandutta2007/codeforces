#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const long double pi=acos(-1.0);
const LL P=32768;
const LL MOD=1e9+7; 
const LL N=30005*4;
LL n,k;
//LL f[N][N];
LL fac[N];
LL JC[N],inv[N];
LL Pow_num (LL x,LL y)
{
	if (y==0) return 1;
	if (y==1) return x;
	LL lalal=Pow_num(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL C (LL x,LL y)	{return JC[x]*inv[y]%MOD*inv[x-y]%MOD;}
struct qq
{
	int n;
	LL a[N];
	void print ()
	{
		for (int u=0;u<=n;u++) printf("%lld ",a[u]);
		printf("\n");
	}
}one;//
qq a,b,c;
struct qt
{
	long double a,b;
	qt () {};
	qt (long double _a,long double _b)	{a=_a;b=_b;}
}a1[N],b1[N],a2[N],b2[N],c1[N],c2[N],c3[N];
qt operator + (qt x,qt y)	{return qt(x.a+y.a, x.b+y.b);}
qt operator - (qt x,qt y)	{return qt(x.a-y.a, x.b-y.b);}
qt operator * (qt x,qt y)	{return qt(x.a*y.a-x.b*y.b, x.a*y.b+x.b*y.a);}
int bin[N];
void FFT (qt *a,int n,int o)
{
	for (int u=0;u<n;u++) 	bin[u]=(bin[u>>1]>>1)|((u&1)*(n>>1));
	for (int u=1;u<n;u++)
		if (u<bin[u])
			swap(a[u],a[bin[u]]);
	for (int u=1;u<n;u<<=1)
	{
		qt w,t,wn=qt(cos(2*pi/(u<<1)),o*sin(2*pi/(u<<1)));
		for (int i=0;i<n;i=i+(u<<1))
		{
			w=qt(1,0);
			for (int j=0;j<u;j++)
			{
				t=w*a[u+i+j];
				a[u+i+j]=a[i+j]-t;
				a[i+j]=a[i+j]+t;
				w=w*wn;
			}
		}
	}
	if (o==-1)	for (int u=0;u<n;u++) a[u].a=a[u].a/n;
}
qq mul (qq x,qq y)
{
	int n2=x.n+y.n,n1=1;
	while (n1<=n2) n1<<=1;
	for (int u=0;u<=k;u++)
	{
		a1[u].a=x.a[u]/P;a1[u].b=0;
		a2[u].a=x.a[u]%P;a2[u].b=0;
		b1[u].a=y.a[u]/P;b1[u].b=0;
		b2[u].a=y.a[u]%P;b2[u].b=0;
	}
	for (int u=k+1;u<n1;u++)
	{
		a1[u].a=0;a1[u].b=0;
		a2[u].a=0;a2[u].b=0;
		b1[u].a=0;b1[u].b=0;
		b2[u].a=0;b2[u].b=0;
	}
	FFT(a1,n1,1);FFT(a2,n1,1);FFT(b1,n1,1);FFT(b2,n1,1);
	for (int u=0;u<n1;u++)
	{
		c1[u]=a1[u]*b1[u];
		c2[u]=a1[u]*b2[u]+a2[u]*b1[u];
		c3[u]=a2[u]*b2[u];
	}
	FFT(c1,n1,-1);FFT(c2,n1,-1);FFT(c3,n1,-1);
	qq z;z.n=n2;
	for (int u=0;u<=n2;u++)
	{
		z.a[u]=((LL)(c1[u].a+0.5)*P%MOD*P%MOD+(LL)(c2[u].a+0.5)*P%MOD+(LL)(c3[u].a+0.5))%MOD;
	}
	return z;
}
qq Pow (int x)
{
	if (x==1) return one;
	int t=(x>>1);
	qq lalal=Pow(t);
	/*lalal*lalal*/
	//lalal.print();
	a.n=k;b.n=k;
	for (int u=0;u<=k;u++) a.a[u]=lalal.a[u]*Pow_num(2,u*t)%MOD;
	for (int u=0;u<=k;u++) b.a[u]=lalal.a[u];
	//a.print();b.print();
	c=mul(a,b);
	//c.print();
	for (int u=0;u<=k;u++) lalal.a[u]=c.a[u];
	//lalal.print();
	/**/
	if (x&1)// 
	{
		//printf("NO\n");
		/*qq now;
		for (int u=1;u<=k;u++) now.a[u]=lalal.a[u],lalal.a[u]=0;
		for (LL i=1;i<=k;i++)
			for (LL j=0;j<i;j++)
				lalal.a[i]=(lalal.a[i]+now.a[j]*fac[j]%MOD*inv[i-j]%MOD)%MOD;*/
		a.n=k;b.n=k;
		for (int u=0;u<=k;u++) a.a[u]=lalal.a[u]*fac[u]%MOD;
		for (int u=0;u<=k;u++) lalal.a[u]=0;
		b.a[0]=0;for (int u=1;u<=k;u++) b.a[u]=inv[u];
		/*for (LL i=1;i<=k;i++)
			for (LL j=0;j<i;j++)
				lalal.a[i]=(lalal.a[i]+a.a[j]*b.a[i-j]%MOD)%MOD;*/
		c=mul(a,b);
		for (int u=0;u<=k;u++) lalal.a[u]=c.a[u];
	}
	return lalal;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	if (n>k)	{printf("0\n");return 0;}
	fac[0]=1;for (LL u=1;u<=k;u++) fac[u]=fac[u-1]*2%MOD;
	JC[0]=1;for (int u=1;u<=k;u++) JC[u]=JC[u-1]*u%MOD;
	inv[k]=Pow_num(JC[k],MOD-2);
	for (int u=k-1;u>=0;u--) inv[u]=inv[u+1]*(u+1)%MOD;
	one.n=k;for (int u=1;u<=k;u++) one.a[u]=inv[u];
	qq f=Pow(n);
	/*f[0][0]=1;
	for (LL u=1;u<=n;u++)
		for (LL i=1;i<=k;i++)
			for (LL j=0;j<i;j++)
				f[u][i]=f[u][i]+f[u-1][j]*fac[j]%MOD*C(k-j,i-j)%MOD;*/
	//f.print();
	LL ans=0;
	for (LL u=1;u<=k;u++)		ans=(ans+f.a[u]*C(k,u)%MOD*JC[u])%MOD;
	printf("%lld\n",ans);
	return 0;
}
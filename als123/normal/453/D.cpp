#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
typedef long double db;
const LL N=21;
LL a[1<<N];
LL b[1<<N],c[1<<N];
LL tmp[1<<N];
LL MOD,t,n,m;
LL bin[1<<N];
/*LL mul (LL x,LL y)
{
	if (y==0) return 0;
	if (y==1) return x;
	LL lalal=mul(x,y>>1);
	lalal=(lalal+lalal)%MOD;
	if (y&1) lalal=(lalal+x)%MOD;
	return lalal;
}*/
LL mul( LL A, LL B )
{
    LL temp = ( ( LL ) ( ( db ) A*B/MOD+1e-6 ) * MOD );
    return A*B - temp;
}
LL Pow (LL x,LL y)
{
	if (y==1) return x;
	LL lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
void FWT (LL *a,LL n,LL o)
{
	for (LL u=1;u<n;u<<=1)// 
		for (LL i=0;i<n;i++)
			if (i&u)	
			{
				LL x=a[i],y=a[i^u];
				a[i]=((y-x)%MOD+MOD)%MOD;
				a[i^u]=(y+x)%MOD;
				if (o==-1)	{a[i]/=2;a[i^u]/=2;}
			}
}
int main()
{
	scanf("%lld%lld%lld",&m,&t,&MOD);n=(1<<m);MOD=MOD*n;
	for (LL u=0;u<n;u++) scanf("%lld",&a[u]);
	for (LL u=0;u<n;u++) bin[u]=bin[u>>1]+(u&1);
	for (LL u=0;u<=m;u++) scanf("%lld",&c[u]);
	for (LL u=0;u<n;u++) b[u]=c[bin[u]];
	FWT(a,n,1);FWT(b,n,1);
	for (LL u=0;u<n;u++)
	{
		b[u]=Pow(b[u],t);
		a[u]=mul(a[u],b[u]);
	}
	FWT(a,n,-1);MOD/=n;
	for (LL u=0;u<n;u++) printf("%lld\n",a[u]%MOD);
	return 0;
}
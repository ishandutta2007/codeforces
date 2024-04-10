#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
ll n,m,w,a[N],b[N],A,B,C,x,y;
int K,i;
ll mult(ll a,ll b,ll md)
{
	ll rtn=0;
	while(b)
	{
		if(b&1)
			rtn=(rtn+a)%md;
		a=(a+a)%md;
		b>>=1;
	}
	return rtn;
}
ll gcd(ll a,ll b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll rtn=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return rtn;
}
int main()
{
	scanf("%lld%lld%d",&n,&m,&K);
	w=1;
	for(i=1;i<=K;++i)
	{
		scanf("%lld",a+i);
		if(w/gcd(w,a[i])>n/a[i])
		{
			printf("NO");
			return 0;
		}
		w=w/gcd(w,a[i])*a[i];
		b[i]=(a[i]-(i-1)%a[i])%a[i];
	}
	A=a[1],B=b[1];
	for(i=2;i<=K;++i)
	{
		w=exgcd(A,a[i],x,y);
		if((b[i]-B)%w!=0)
		{
			printf("NO");
			return 0;
		}
		C=A;
		A=C/w*a[i];
		x=mult(((b[i]-B)/w%A+A)%A,(x%A+A)%A,A);
		B=(mult((C%A+A)%A,x,A)+B)%A;
	}
	if(B==0)
		B=A;
	if(B+K-1<=m)
	{
		for(i=1;i<=K;++i)
			if(gcd(A,B+i-1)!=a[i])
			{
				printf("NO");
				return 0;
			}
		printf("YES");
	}
	else
		printf("NO");
	return 0;
}
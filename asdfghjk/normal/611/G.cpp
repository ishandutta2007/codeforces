#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1000005,md=1000000007;
struct node
{
	ll x,y;
}a[N],sum[N];
int n,i,j,l,r;
ll ss[N],ans,S[N],tk;
unsigned long long All,w;
ll mult(node a,node b)
{
	return (1ll*(a.x%md+md)*(b.y%md+md)%md-1ll*(a.y%md+md)*(b.x%md+md)%md+md)%md;
}
unsigned long long Mult(node a,node b)
{
	return (unsigned long long)a.x*b.y-(unsigned long long)a.y*b.x;
}
node operator +(node a,node b)
{
	return (node){a.x+b.x,a.y+b.y};
}
node operator -(node a,node b)
{
	return (node){a.x-b.x,a.y-b.y};
}
ll Work(int l,int r)
{
	if(r-l<2)
		return 0;
	return (ss[r-1]-ss[l]-S[l-1]*(r-l-1)%md+mult(sum[r]-sum[l+1],a[l])%md+2*md)%md;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%lld%lld",&a[n-i+1].x,&a[n-i+1].y);
	for(i=1;i<=n;++i)
		a[n+i]=a[i];
	for(i=1;i<2*n;++i)
		S[i]=(S[i-1]+mult(a[i],a[i+1])%md+md)%md;
	for(i=1;i<=2*n;++i)
	{
		ss[i]=(ss[i-1]+S[i])%md;
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n;++i)
		All+=(unsigned long long)a[i].x*a[i+1].y-(unsigned long long)a[i].y*a[i+1].x;
	tk=S[n];
	for(l=1,r=2,w=0;l<=n;++l)
	{
		while(r<l+n-2&&w-Mult(a[r],a[l])+Mult(a[r],a[r+1])+Mult(a[r+1],a[l])<=All/2)
		{
			w=w-Mult(a[r],a[l])+Mult(a[r],a[r+1])+Mult(a[r+1],a[l]);
			++r;
		}
		ans=(ans+tk*(r-l-1)%md-2*Work(l,r)%md+md)%md;
		ans=(ans-tk*(l+n-2-r)%md+2*(Work(l,l+n-2)-Work(l,r)+md)%md+md)%md;
		w=w-Mult(a[l],a[l+1])-Mult(a[r],a[l])+Mult(a[r],a[l+1]);
	}
	ans=(md+1)/2*ans%md;
	printf("%lld",ans);
	return 0;
}
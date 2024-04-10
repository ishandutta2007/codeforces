#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200005;
struct node
{
	ll l,r;
}A,B,C,D,E;
int t,n,i,j,k,l;
ll x[N],y[N],z[N],a[N],b[N],c[N],d[N],lt,rt,mid,ansx,ansy,ansz,mn,mx,X,Y,Z;
ll Abs(ll a)
{
	return a>0?a:-a;
}
node work(ll a,ll b,ll w)
{
	return (node){b-w,a+w};
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%lld%lld%lld",x+i,y+i,z+i);
			a[i]=x[i]+y[i]+z[i],b[i]=x[i]+y[i]-z[i],c[i]=x[i]-y[i]+z[i],d[i]=x[i]-y[i]-z[i];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n);
		sort(d+1,d+1+n);
		lt=max(max(a[n]-a[1],b[n]-b[1]),max(c[n]-c[1],d[n]-d[1]))/2,rt=3000000000000000005ll;
		while(lt<rt)
		{
			mid=lt+rt>>1;
			A=work(a[1],a[n],mid),B=work(b[1],b[n],mid),C=work(c[1],c[n],mid),D=work(d[1],d[n],mid);
			if(B.l+C.l>A.r+D.r||B.r+C.r<A.l+D.l)
				lt=mid+1;
			else
				rt=mid;
		}
		mid=lt;
		A=work(a[1],a[n],mid),B=work(b[1],b[n],mid),C=work(c[1],c[n],mid),D=work(d[1],d[n],mid);
		E=(node){A.r+D.l>B.l+C.l?D.l:-A.r+B.l+C.l,D.r+A.l<B.r+C.r?D.r:-A.l+B.r+C.r};
		d[0]=E.l;
		lt=C.l,rt=C.r;
		while(lt<rt)
		{
			mid=lt+rt>>1;
			if(B.l+mid>A.r+d[0])
				rt=mid-1;
			else if(B.r+mid<A.l+d[0])
				lt=mid+1;
			else
			{
				lt=mid;
				break;
			}
		}
		c[0]=lt;
		lt=B.l,rt=B.r;
		while(lt<rt)
		{
			mid=lt+rt>>1;
			if(mid+c[0]>A.r+d[0])
				rt=mid-1;
			else if(mid+c[0]<A.l+d[0])
				lt=mid+1;
			else
			{
				lt=mid;
				break;
			}
		}
		b[0]=lt;
		a[0]=b[0]+c[0]-d[0];
		x[0]=(b[0]+c[0])/2,y[0]=(a[0]-c[0])/2,z[0]=(a[0]-b[0])/2;
		mn=(((unsigned long long)1)<<63)-1;
		for(i=-2;i<=2;++i)
			for(j=-2;j<=2;++j)
				for(k=-2;k<=2;++k)
				{
					X=x[0]+i,Y=y[0]+j,Z=z[0]+k;
					mx=0;
					for(l=1;l<=n;++l)
						mx=max(mx,Abs(X-x[l])+Abs(Y-y[l])+Abs(Z-z[l]));
					if(mx<mn)
					{
						mn=mx;
						ansx=X,ansy=Y,ansz=Z;
					}
				}
		printf("%lld %lld %lld\n",ansx,ansy,ansz);
	}
	return 0;
}
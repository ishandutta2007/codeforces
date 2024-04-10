#include<bits/stdc++.h>
using namespace std;
#define db double
#define X first
#define Y second
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;++i)
const int N=100005;
const db pi=acos(-1.0);
int n,m,f[N],f1[N],g[N],g1[N];db d[N],ang[N];
pair<db,db>a[N],q[N<<1];
inline bool chk(db r,int m)
{
	rep(i,1,n)
	{
		db A=acos(r/d[i]);q[i]=mp(ang[i]+A,ang[i]-A);
		if(q[i].X>pi*2)q[i].X-=pi*2,q[i].Y-=pi*2;
	}
	sort(q+1,q+n+1);int j=1;
	rep(i,1,n)q[n+i]=mp(q[i].X+pi*2,q[i].Y+pi*2);
	rep(i,1,n)
	{
		for(;q[j].Y<=q[i].X&&j<n*2;++j);
		f[i]=j;g[i]=i;
	}
	for(int x=1;m;x<<=1)
	{
		if(m&x)
		{
			rep(i,1,n)g1[i]=g[(f[i]-1)%n+1]+(f[i]-1)/n*n;
			rep(i,1,n)if(g1[i]>=n+i)return 1;
			m-=x;memcpy(g,g1,sizeof(g));
		}
		rep(i,1,n)f1[i]=f[(f[i]-1)%n+1]+(f[i]-1)/n*n;
		memcpy(f,f1,sizeof(f));
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lf%lf",&a[i].X,&a[i].Y);
	db l=0,r=200000,mid;
	rep(i,1,n){d[i]=sqrt(a[i].X*a[i].X+a[i].Y*a[i].Y);r=min(r,d[i]);ang[i]=acos(a[i].X/d[i]);if(a[i].Y<0)ang[i]=2*pi-ang[i];}
	while(r-l>2e-7)if(chk(mid=(l+r)/2,m))l=mid;else r=mid;
	printf("%.10lf\n",l);
	return 0;
}
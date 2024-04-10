#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
const int N=3005;
const db pi=acos(-1.0);
int n;
struct P{ll x,y;}p[N],q[N];
inline P operator-(const P&a,const P&b){return (P){a.x-b.x,a.y-b.y};}
inline ll crs(P a,P b){return a.x*b.y-a.y*b.x;}
inline bool cmp(P a,P b)
{
	if(a.y<0&&b.y>0)return 0;
	if(a.y>0&&b.y<0)return 1;
	if(!a.y)return a.x<0?b.y<0:b.y>0;
	if(!b.y)return !cmp(b,a);
	return crs(a,b)>0;
}
inline ll sol()
{
	ll t1=0;
	for(int k=0;k<n;k++)
	{
		ll t2=1ll*(n-1)*(n-2)*(n-3)/6;int m=0;
		for(int i=0;i<n;i++)if(k!=i)q[m++]=(P){p[i].x-p[k].x,p[i].y-p[k].y};
		sort(q,q+m,cmp);
		for(int i=0,j=0;i<m;i++)
		{
			for(;j<i+m;j++)if(crs(q[i],q[j%m])<0)break;
			t2-=1ll*(j-i-1)*(j-i-2)/2;
		}
		t1+=t2;
	}
	return t1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&p[i].x,&p[i].y);
	printf("%lld\n",sol()*(n-4)/2);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005;
typedef pair<pii,pii> ppp;

int n,p[MAXN],q[MAXN];
ppp a[MAXN];
int mx[MAXN<<2|1],lazy[MAXN<<2|1];
ll sum[MAXN<<2|1],laz2[MAXN<<2|1];
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(l==ql && r==qr){lazy[id]+=c;laz2[id]+=max(c,0);return;}
	int mid=(l+r)>>1;
	lazy[id<<1]+=lazy[id],lazy[id<<1|1]+=lazy[id];
	laz2[id<<1]+=laz2[id],laz2[id<<1|1]+=laz2[id];
	sum[id]+=1ll*laz2[id]*(r-l+1),mx[id]-=lazy[id];
	lazy[id]=laz2[id]=0;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
	else modify(id<<1,l,mid,ql,mid,c),modify(id<<1|1,mid+1,r,mid+1,qr,c);
	mx[id]=max(mx[id<<1]-lazy[id<<1],mx[id<<1|1]-lazy[id<<1|1]); 
	sum[id]=sum[id<<1]+sum[id<<1|1]+laz2[id<<1]*(mid-l+1)+laz2[id<<1|1]*(r-mid);
}
ll query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return sum[id]+laz2[id]*(r-l+1);
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}
vector<pii> d[MAXN],e[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		readint(a[i].x.x),readint(a[i].x.y),readint(a[i].y.x),readint(a[i].y.y);
		p[i*2-1]=a[i].x.x,p[i*2]=a[i].x.y;
		q[i*2-1]=a[i].y.x,q[i*2]=a[i].y.y;
	}
	sort(p+1,p+2*n+1);
	sort(q+1,q+2*n+1);
	for(int i=1;i<=n;++i)
	{
		a[i].x.x=lower_bound(p+1,p+2*n+1,a[i].x.x)-p,
		a[i].x.y=lower_bound(p+1,p+2*n+1,a[i].x.y)-p;
		a[i].y.x=lower_bound(q+1,q+2*n+1,a[i].y.x)-q,
		a[i].y.y=lower_bound(q+1,q+2*n+1,a[i].y.y)-q;
		d[a[i].x.x].pb(a[i].y);
		e[a[i].x.y+1].pb(a[i].y);
	}
	int cur=0;
	for(int i=1;i<=2*n;++i)
	{
		for(auto p:e[i])
		{
			modify(1,1,2*n,p.x,p.y,1),--cur;
		}
		for(auto p:d[i])
		{
			modify(1,1,2*n,p.x,p.y,-1),++cur;
			if(mx[1]-lazy[1]<cur)return 0*printf("NO\n");
			if(query(1,1,2*n,p.x,p.y)>0)return 0*printf("NO\n");
		}
	}
	printf("YES\n");
	return 0;
}
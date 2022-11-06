#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,b,a) for(register int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(register int i=(a);i<(b);++i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
#define gc() getchar()
#define lc x<<1
#define rc x<<1|1
#define ls lc,l,m
#define rs rc,m+1,r
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=150005;
int n,a[N],b[N];ll ans[N];
struct st{int mx,sx,cx,tg,sz;ll s;}T[N*4];
void build(int x,int l,int r)
{
	T[x]=(st){0,0,0,0,0,0};if(l==r)return;
	int m=l+r>>1;build(ls);build(rs);
}
inline void up(int x)
{
	int l=lc,r=rc;
	if(T[l].mx>T[r].mx)T[x].mx=T[l].mx,T[x].sx=max(T[l].sx,T[r].mx),T[x].cx=T[l].cx;
	else if(T[r].mx>T[l].mx)T[x].mx=T[r].mx,T[x].sx=max(T[r].sx,T[l].mx),T[x].cx=T[r].cx;
	else T[x].mx=T[l].mx,T[x].sx=max(T[l].sx,T[r].sx),T[x].cx=T[l].cx+T[r].cx;
	T[x].sz=T[l].sz+T[r].sz;T[x].s=T[l].s+T[r].s;
}
inline void cov(int x,int v)
{
	if(T[x].mx)T[x].mx+=v;if(T[x].sx)T[x].sx+=v;
	T[x].s+=1ll*T[x].sz*v;T[x].tg+=v;
}
inline void dn(int x)
{
	if(T[x].tg){cov(lc,T[x].tg);cov(rc,T[x].tg);T[x].tg=0;}
	if(T[lc].mx>T[x].mx){T[lc].s-=1ll*(T[lc].mx-T[x].mx)*T[lc].cx;T[lc].mx=T[x].mx;}
	if(T[rc].mx>T[x].mx){T[rc].s-=1ll*(T[rc].mx-T[x].mx)*T[rc].cx;T[rc].mx=T[x].mx;}
}
void add(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr){cov(x,1);return;}
	int m=l+r>>1;dn(x);
	if(tl<=m)add(lc,l,m,tl,tr);
	if(tr>m)add(rc,m+1,r,tl,tr);
	up(x);
}
int qry(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr)return T[x].sz;int m=l+r>>1;dn(x);
	return (tl<=m?qry(ls,tl,tr):0)+(tr>m?qry(rs,tl,tr):0);
}
void ins(int x,int l,int r,int p,int v)
{
	if(l==r){T[x]=(st){v,0,1,0,1,v};return;}
	int m=l+r>>1;dn(x);p<=m?ins(ls,p,v):ins(rs,p,v);up(x);
}
void upd(int x,int l,int r,int tl,int tr,int v)
{
	if(tl<=l&&r<=tr&&T[x].mx<=v)return;
	if(tl<=l&&r<=tr&&T[x].sx<v){T[x].s-=1ll*(T[x].mx-v)*T[x].cx;T[x].mx=v;return;}
	int m=l+r>>1;dn(x);if(tl<=m)upd(ls,tl,tr,v);if(tr>m)upd(rs,tl,tr,v);up(x);
}
int main()
{
	n=rd();
	rep(i,1,n)a[i]=rd();
	rep(i,1,n)b[a[i]]=i;
	build(1,1,n);
	rep(i,1,n)
	{
		if(b[i]<n)add(1,1,n,b[i]+1,n);
		int t=qry(1,1,n,1,b[i]);
		if(t)upd(1,1,n,1,b[i],t);
		ins(1,1,n,b[i],i);
		ans[i]=T[1].s+i;
	}
	reverse(a+1,a+n+1);
	rep(i,1,n)b[a[i]]=i;
	build(1,1,n);
	rep(i,1,n)
	{
		if(b[i]<n)add(1,1,n,b[i]+1,n);
		int t=qry(1,1,n,1,b[i]);
		if(t)upd(1,1,n,1,b[i],t);
		ins(1,1,n,b[i],i);
		ans[i]-=1ll*i*(i+1)-T[1].s;
	}
	rep(i,1,n)printf("%lld\n",ans[i]);
	return 0;
}
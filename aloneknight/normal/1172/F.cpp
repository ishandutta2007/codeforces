#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=1e6+5;
const ll inf=1000000000000000ll;
int n,m,P,a[N];
struct st{ll l,b;};//y=x+b(x\in [l,r))
#define vt vector<st>
vt T[N*4];
inline void merge(vt&c,vt a,vt b)
{
	for(int i=0,j=0;i<a.size();)
	{
		ll vl=(a[i].l==inf?-inf:a[i].l+a[i].b),vr=(i==a.size()-1?inf:a[i+1].l-1+a[i].b);
		while(j&&b[j].l>vl)j--;while(j+1<b.size()&&b[j+1].l-1<vl)j++;
		ll ed=(j+1==b.size()?inf:b[j+1].l-1);
		if(ed<vr)
		{
			if(!c.size()||c.back().b!=a[i].b+b[j].b)c.pb((st){a[i].l,a[i].b+b[j].b});
			a[i].l=ed-a[i].b+1;
		}
		else
		{
			if(!c.size()||c.back().b!=a[i].b+b[j].b)c.pb((st){a[i].l,a[i].b+b[j].b});
			i++;
		}
	}
}
inline ll calc(const vt&a,ll x)
{
	int l=0,r=a.size()-1,m,p=0;
	while(l<=r)if(a[m=l+r>>1].l<=x)l=m+1,p=m;else r=m-1;
	return x+a[p].b;
}
void build(int x,int l,int r)
{
	if(l==r){T[x].pb((st){-inf,a[l]});T[x].pb((st){P-a[l],a[l]-P});return;}
	int m=l+r>>1;build(ls);build(rs);merge(T[x],T[x<<1],T[x<<1|1]);
}
ll qry(int x,int l,int r,int tl,int tr,ll v)
{
	if(tl<=l&&r<=tr)return calc(T[x],v);int m=l+r>>1;
	if(tl<=m)v=qry(ls,tl,tr,v);if(tr>m)v=qry(rs,tl,tr,v);return v;
}
int main()
{
	n=rd();m=rd();P=rd();rep(i,1,n)a[i]=rd();build(1,1,n);
	while(m--){int l=rd(),r=rd();printf("%lld\n",qry(1,1,n,l,r,0));}
	return 0;
}
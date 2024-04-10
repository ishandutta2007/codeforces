#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q,qt1,qt2,a[N],qmx[N],qmn[N];ll ans[N];
struct qr{int l,r,i;}qq[N];
bool operator<(qr a,qr b){return a.l<b.l;}
struct st{int mn,c,tg,v;ll s;}T[N<<2];
inline void up(int x)
{
	T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);
	T[x].s=T[x<<1].s+T[x<<1|1].s;
	T[x].c=(T[x<<1].mn==T[x].mn?T[x<<1].c:0)+(T[x<<1|1].mn==T[x].mn?T[x<<1|1].c:0);
}
void chg(int x,int tg,int v)
{
	if(tg){T[x].mn+=tg;T[x].tg+=tg;}
	if(T[x].mn==T[x>>1].mn||T[x].mn==-1){T[x].s+=1ll*T[x].c*v;T[x].v+=v;}
}
void dn(int x){chg(x<<1,T[x].tg,T[x].v);chg(x<<1|1,T[x].tg,T[x].v);T[x].tg=T[x].v=0;}
void build(int x,int l,int r){if(l==r){T[x].mn=0;T[x].c=1;return;}int mid=l+r>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);up(x);}
void upd(int x,int l,int r,int tl,int tr,int tg,int v)
{
	if(l<r)dn(x);int mid=l+r>>1;
	if(tl<=l&&r<=tr){chg(x,tg,v);return;}
	if(tl<=mid)upd(x<<1,l,mid,tl,tr,tg,v);
	if(tr>mid)upd(x<<1|1,mid+1,r,tl,tr,tg,v);
	up(x);
}
ll qry(int x,int l,int r,int tl,int tr)
{
	if(l<r)dn(x);int mid=l+r>>1;ll res=0;
	if(tl<=l&&r<=tr)return T[x].s;
	if(tl<=mid)res+=qry(x<<1,l,mid,tl,tr);
	if(tr>mid)res+=qry(x<<1|1,mid+1,r,tl,tr);
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){int l,r;scanf("%d%d",&l,&r);qq[i]=(qr){l,r,i};}
	sort(qq+1,qq+q+1);build(1,1,n);
	for(int i=q,x=n+1;i>=1;i--)
	{
		while(qq[i].l<x)
		{
			x--;
			while(qt1&&a[x]>a[qmx[qt1]])
			{
				int l=qmx[qt1--],r=qt1?qmx[qt1]-1:n;
				upd(1,1,n,l,r,a[x]-a[l],0);
			}
			while(qt2&&a[x]<a[qmn[qt2]])
			{
				int l=qmn[qt2--],r=qt2?qmn[qt2]-1:n;
				upd(1,1,n,l,r,a[l]-a[x],0);
			}
			upd(1,1,n,x,n,-1,0);upd(1,1,n,x,n,0,1);
			qmx[++qt1]=x;qmn[++qt2]=x;
		}
		ans[qq[i].i]=qry(1,1,n,qq[i].l,qq[i].r);
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}
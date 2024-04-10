#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct query{ll num,x;friend bool operator<(query a,query b){return a.x<b.x;}}q[200002];
ll n,m;
struct ST{
	struct node{
		ll l,r,val;
	}s[800008];
	inline void push_up(ll k){s[k].val=s[k<<1].val+s[k<<1|1].val;}
	inline void build(ll k,ll l,ll r){
		s[k].l=l;s[k].r=r;
		if(l==r)return;
		ll mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	inline void update(ll k,ll ind,ll x){
		if(s[k].l==s[k].r){
			s[k].val=x*(x-1)/2;
			return;
		}
		ll mid=(s[k].l+s[k].r)>>1;
		if(ind<=mid)
			update(k<<1,ind,x);
		else
			update(k<<1|1,ind,x);
		push_up(k);
	}
}seg;
ll fa[200002],sz[200002],ans[200002];
ll get(ll x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void UPD(ll a,ll b)
{
	ll x=get(a),y=get(b);
	if(x==y)return;
	fa[x]=y,sz[y]+=sz[x],sz[x]=0;
	seg.update(1,x,0);
	seg.update(1,y,sz[y]);
}
void init()
{
	for(ll i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
	seg.build(1,1,n);
}
struct edg{ll u,v,w;friend bool operator<(edg a,edg b){return a.w<b.w;}}e[200002];
vector <edg> g[200002];
int main(){
	cin>>n>>m;
	for(ll i=1;i<n;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(ll i=1;i<=m;i++)
		cin>>q[i].x,q[i].num=i;
	sort(e+1,e+n);sort(q+1,q+1+m);
	init();
	ll pos=1;
	for(ll i=1;i<=m;i++){
		while(e[pos].w<=q[i].x&&pos<n)
			UPD(e[pos].u,e[pos].v),pos++;
		ans[q[i].num]=seg.s[1].val;
	}
	for(ll i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+3;
ll n,m,k,a[N],st[N<<2],laz[N<<2],l[N],r[N],d[N],p[N];
void build(ll l,ll r,ll x)
{
	if(l==r){st[x]=a[l];return;}
	ll m=l+r>>1;
	build(l,m,x<<1);
	build(m+1,r,x<<1|1);
}
void push_down(ll l,ll r,ll x)
{
//	cout<<l<<" "<<r<<" "<<laz[x]<<endl;
	if(l==r){st[x]+=laz[x],laz[x]=0;return;}
	laz[x<<1]+=laz[x],laz[x<<1|1]+=laz[x],laz[x]=0;
}
void upd(ll l,ll r,ll ul,ll ur,ll x,ll w)
{
	if(ul<=l&&r<=ur){laz[x]+=w;return;}
	ll m=l+r>>1;
	if(m>=ul)upd(l,m,ul,ur,x<<1,w);
	if(m<ur)upd(m+1,r,ul,ur,x<<1|1,w);
}
ll query(ll l,ll r,ll num,ll x)
{
//	cout<<l<<" "<<r<<" "<<num<<" "<<st[x]<<endl;
	push_down(l,r,x);
	if(l==r)return st[x];
	ll m=l+r>>1;
	if(m>=num)return query(l,m,num,x<<1);
	else return query(m+1,r,num,x<<1|1);
}
int main()
{
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=m;i++)
		cin>>l[i]>>r[i]>>d[i];
	for(ll i=1;i<=k;i++){
		ll x,y;
		cin>>x>>y;
		p[x]++,p[y+1]--;
	}
	build(1,n,1);
	for(ll i=1;i<=m;i++)
		p[i]+=p[i-1],upd(1,n,l[i],r[i],1,d[i]*p[i]);
	for(ll i=1;i<=n;i++)
		cout<<query(1,n,i,1)<<" ";
    return 0;
}
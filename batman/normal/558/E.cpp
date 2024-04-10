#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll MOD=((ll)1e9+7);
const ll N =101*1000;
const ll K=26;

ll n,m,seg[K][4*N],lazy[K][4*N];
char str[N];
ll ans[N];

void shift(ll xl,ll xr,ll id,ll bit)
{
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	if(lazy[bit][id]==0)return ;
	lazy[bit][l]=lazy[bit][id];
	lazy[bit][r]=lazy[bit][id];
	if(lazy[bit][id]==2)seg[bit][l]=mid-xl,seg[bit][r]=xr-mid;
	if(lazy[bit][id]==1)seg[bit][l]=seg[bit][r]=0;
	lazy[bit][id]=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll bit,ll lzy)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		lazy[bit][id]=lzy;
		if(lazy[bit][id]==2)seg[bit][id]=xr-xl;
		if(lazy[bit][id]==1)seg[bit][id]=0;
		return ;
	}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(xl,xr,id,bit);
	update(ql,qr,xl,mid,l,bit,lzy);
	update(ql,qr,mid,xr,r,bit,lzy);
	seg[bit][id]=seg[bit][l]+seg[bit][r];
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id,ll bit)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[bit][id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(xl,xr,id,bit);
	return query(ql,qr,xl,mid,l,bit)+
			query(ql,qr,mid,xr,r,bit);
}

void out(ll xl,ll xr,ll id,ll bit)
{
	if(xl>=xr)return ;
	if(xl==xr-1)
	{
		if(seg[bit][id])
			ans[xl]=bit;
		return ;
	}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(xl,xr,id,bit);
	out(xl,mid,l,bit);
	out(mid,xr,r,bit);
}

int main()
{
   	scanf("%d%d",&n,&m);
   	scanf("%s",str);
	for(int i=0;i<n;i++)update(i,i+1,0,N,1,str[i]-'a',2);
	while(m--)
	{
		ll l,r,p;
		scanf("%d%d%d",&l,&r,&p);
		l--;r--;
		for(int i=0,new_l=l;i<K && p;i++)
		{
			ll new_l2=new_l+query(l,r+1,0,N,1,i)-1;
			update(l,r+1,0,N,1,i,1);
			update(new_l,new_l2+1,0,N,1,i,2);
			new_l=new_l2+1;
		}
		for(int i=K-1,new_l=l;i>=0 && !p;i--)
		{
			ll new_l2=new_l+query(l,r+1,0,N,1,i)-1;
			update(l,r+1,0,N,1,i,1);
			update(new_l,new_l2+1,0,N,1,i,2);
			new_l=new_l2+1;
		}
	}
	for(int i=0;i<K;i++)out(0,N,1,i);
	for(int i=0;i<n;i++)printf("%c",(char)(ans[i]+'a'));
	return 0;
}
// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((101*1000))

ll n,k,a[N],ans,seg[4*N];
bool lazy[4*N];
vector <ll> l[N],r[N];

void shift(ll xl,ll xr,ll id)
{
	ll mid=xl+xr>>1;
	if(lazy[id]==0)return ;
	seg[id*2]=mid-xl-seg[id*2];
	seg[id*2+1]=xr-mid-seg[id*2+1];
	lazy[id*2]=!lazy[id*2];
	lazy[id*2+1]=!lazy[id*2+1];
	lazy[id]=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(xr<=ql || qr<=xl)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id]=xr-xl-seg[id];
		lazy[id]=!lazy[id];
		//cout<<xl<<" "<<xr<<" "<<seg[id]<<"\n";
		return ;
	}
	shift(xl,xr,id);
	ll mid=xl+xr>>1;
	update(ql,qr,xl,mid,id*2);
	update(ql,qr,mid,xr,id*2+1);
	seg[id]=seg[id*2]+seg[id*2+1];
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(xr<=ql || qr<=xl)return 0;
	if(ql<=xl && xr<=qr)return seg[id];
	shift(xl,xr,id);
	ll mid=xl+xr>>1;
	return query(ql,qr,xl,mid,id*2)+query(ql,qr,mid,xr,id*2+1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    
    cin>>n>>k;
    ans=n*(n-1)*(n-2)/6;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<k;i++)
    {
    	ll x,y;
    	cin>>x>>y;
    	x=lower_bound(a,a+n,x)-a;y=upper_bound(a,a+n,y)-a;
    	l[x].push_back(y);
    	r[y].push_back(x);
    	//cout<<x<<" "<<y<<"\n";
	}
	//update(0,4,0,n,1);
	//cout<<query(1,n,0,n,1);
	//cout<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<l[i].size();j++)update(i,l[i][j],0,n,1);
		for(int j=0;j<r[i].size();j++)update(r[i][j],i,0,n,1);
		ll deg=query(i+1,n,0,n,1)+(i-query(0,i,0,n,1));
		ans-=deg*(deg-1)/2;
	}
	cout<<ans;	
    return 0;
}
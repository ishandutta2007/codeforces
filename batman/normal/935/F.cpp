#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)
#define INF ((ll)2e18)

ll n,a[N],seg[4*N],ans;

void update(ll q,ll val,ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1)
	{
		ans-=abs(a[xl]);
		a[xl]+=val;
		ans+=abs(a[xl]);
		if(xr<n)seg[id]=max(0ll,-a[xl])+max(0ll,a[xr]);
		if(val)update(q-1,0);
		return ;
	}
	ll mid=(xl+xr)/2;
	if(q<mid)update(q,val,xl,mid,id*2);
	else update(q,val,mid,xr,id*2+1);
	seg[id]=min(seg[id*2],seg[id*2+1]);
	seg[id]=min(seg[id],max(0ll,-a[mid-1])+max(0ll,a[mid]));
}

ll query(ll ql,ll qr,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return INF;
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	return min(query(ql,qr,xl,mid,id*2),query(ql,qr,mid,xr,id*2+1));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=0;i<N;i++)seg[i]=INF;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		if(i)a[i-1]=a[i]-a[i-1];
	}
	n--;
	for(ll i=0;i<n;i++)
	{
		ll ex=a[i];a[i]=0;
		update(i,ex);
	}
	ll q;cin>>q;
	while(q--)
	{
		ll t,l,r,x;
		cin>>t>>l>>r>>x;l--;r--;
		if(t==1)
		{
			if(l==r)
			{
				if(l==0)cout<<ans-abs(a[0])+abs(a[0]-x)<<"\n";
				else if(l==n)cout<<ans-abs(a[n-1])+abs(a[n-1]+x)<<"\n";
				else cout<<ans-abs(a[l-1])-abs(a[l])+abs(a[l-1]+x)+abs(a[l]-x)<<"\n";
				continue;
			}
			ll ex=max(x*2-query(max(0ll,l-1),r)*2,0ll);
			if(l==0)ex=max(ex,x-max(0ll,a[0])*2);
			if(r==n)ex=max(ex,x-max(0ll,-a[n-1])*2);
			cout<<ans+ex<<"\n";
		}
		if(t==2)
		{
			if(l>0)update(l-1,x);
			update(r,-x);
		}
	}
	return 0;
}
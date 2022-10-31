#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=301*1000;
const ll MOD=((ll)1e9+9);
const ll INF=((ll)1e9);

ll n,m,a[N],seg[4*N],lazy[2][4*N],f[N];

void build(ll xl,ll xr,ll id)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg[id]=a[xl];return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	build(xl,mid,l);
	build(mid,xr,r);
	seg[id]=(seg[l]+seg[r])%MOD;
}

void shift(ll xl,ll xr,ll id)
{
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	lazy[0][l]+=lazy[0][id];lazy[0][l]%=MOD;
	lazy[1][l]+=lazy[1][id];lazy[1][l]%=MOD;
	seg[l]+=((f[mid-xl+1]-1)*lazy[0][id])%MOD;
	seg[l]+=((f[mid-xl+2]-1)*lazy[1][id])%MOD;
	seg[l]%=MOD;seg[l]+=MOD;seg[l]%=MOD;
	//cout<<xl<<" "<<xr<<"\n";
	ll f1=((f[mid-xl-1]*lazy[0][id])%MOD)+((f[mid-xl]*lazy[1][id])%MOD),f2=((f[mid-xl]*lazy[0][id])%MOD)+((f[mid-xl+1]*lazy[1][id])%MOD);
	//cout<<mid<<" "<<xr<<" "<<f1<<" "<<f2<<"\n";
	f1%=MOD;f2%=MOD;
	lazy[0][r]+=f1;lazy[0][r]%=MOD;
	lazy[1][r]+=f2;lazy[1][r]%=MOD;
	seg[r]+=((f[xr-mid+1]-1)*f1)%MOD;
	seg[r]+=((f[xr-mid+2]-1)*f2)%MOD;
	seg[r]%=MOD;seg[r]+=MOD;seg[r]%=MOD;
	lazy[0][id]=0;
	lazy[1][id]=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll f1,ll f2)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		if(ql==xl)
			lazy[0][id]+=f1,lazy[0][id]%=MOD,lazy[1][id]+=f2,lazy[1][id]%=MOD;
		else 
			lazy[0][id]+=((f[xl-ql-1]*f1)%MOD)+((f[xl-ql]*f2)%MOD),lazy[0][id]%=MOD,
			lazy[1][id]+=((f[xl-ql]*f1)%MOD)+((f[xl-ql+1]*f2)%MOD),lazy[1][id]%=MOD;
		seg[id]+=((f[xr-ql+1]-f[xl-ql+1])*f1)%MOD;
		seg[id]+=((f[xr-ql+2]-f[xl-ql+2])*f2)%MOD;
		seg[id]%=MOD;seg[id]+=MOD;seg[id]%=MOD;
		return ;
	}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(xl,xr,id);
	update(ql,qr,xl,mid,l,f1,f2);
	update(ql,qr,mid,xr,r,f1,f2);
	seg[id]=(seg[l]+seg[r])%MOD;
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(xl,xr,id);
	return (query(ql,qr,xl,mid,l)+
			query(ql,qr,mid,xr,r))%MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	build(0,N,1);
	f[1]=1;
	for(int i=2;i<N;i++)f[i]=(f[i-1]+f[i-2])%MOD;
	while(m--)
	{
		ll t,l,r;
		cin>>t>>l>>r;
		if(t==1)
			update(l-1,r,0,N,1,0,1);
		if(t==2)
			cout<<query(l-1,r,0,N,1)<<"\n";
	}
	return 0;
}
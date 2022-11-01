#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=((n&1)?a:1ll),res%=mod,a*=a,a%=mod,n/=2;return res;}
const int N=200*1000+10;
const int K=1000*1000+10;
const int P=100*1000;
const ll MOD=((ll)1e9+7);

int n,q,a[N],prime[P],prime_place[P];
ll seg_mul[4*N],seg_prime[4*N],ans[N],xx[2][P];
bool mark[K];
vector <int> div_[N],num[K];
vector <pair<int,int> > sg[N];

void build(int xl,int xr,int id)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg_mul[id]=a[xl];return ;}
	int l=id*2,r=l+1,mid=(xl+xr)/2;
	build(xl,mid,l);
	build(mid,xr,r);
	seg_mul[id]=(seg_mul[l]*seg_mul[r])%MOD;
}

void update(int q,int xl,int xr,int id,ll x)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg_prime[id]*=x;seg_prime[id]%=MOD;return ;}
	int l=id*2,r=l+1,mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,l,x);
	else update(q,mid,xr,r,x);
	seg_prime[id]=(seg_prime[l]*seg_prime[r])%MOD;
}

ll query(int ql,int qr,int xl,int xr,int id)
{
	if(qr<=xl || xr<=ql)return 1;
	//cout<<xl<<" "<<xr<<" "<<seg_mul[id]<<"\n";
	if(ql<=xl && xr<=qr)return seg_mul[id];
	int l=id*2,r=l+1,mid=(xl+xr)/2;
	return (query(ql,qr,xl,mid,l)*query(ql,qr,mid,xr,r))%MOD;
}


ll query_prime(int ql,int qr,int xl,int xr,int id)
{
	if(qr<=xl || xr<=ql)return 1;
	if(ql<=xl && xr<=qr)return seg_prime[id];
	int l=id*2,r=l+1,mid=(xl+xr)/2;
	return (query_prime(ql,qr,xl,mid,l)*query_prime(ql,qr,mid,xr,r))%MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],num[a[i]].push_back(i);
	for(int i=0;i<4*N;i++)seg_mul[i]=seg_prime[i]=1;
	build(0,N,1);
	for(ll i=2,id=0;i<K;i++)
	{
		if(!mark[i])
		{
			prime[id]=i;
			for(ll j=i;j<K;j+=i)
			{
				mark[j]=1;
				for(ll k=0;k<num[j].size();k++)
					div_[num[j][k]].push_back(id);
			}
			id++;
		}
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;l--;r--;
		sg[r].push_back({l,i});
	}
	for(int i=0;i<P;i++)prime_place[i]=-1;
	for(int i=0;i<P;i++)
	{
		ll ex=prime[i]-1;ex*=tavan(prime[i],MOD-2,MOD);ex%=MOD;
		xx[0][i]=ex;
		xx[1][i]=tavan(ex,MOD-2,MOD);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<div_[i].size();j++)
		{
			update(i,0,N,1,xx[0][div_[i][j]]);
			if(prime_place[div_[i][j]]!=-1)update(prime_place[div_[i][j]],0,N,1,xx[1][div_[i][j]]);
			prime_place[div_[i][j]]=i;
		}
		for(int j=0;j<sg[i].size();j++)ans[sg[i][j].second]=(query(sg[i][j].first,i+1,0,N,1)*query_prime(sg[i][j].first,i+1,0,N,1))%MOD;
	}
	for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
  	return 0;
}
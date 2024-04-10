#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =1001*1000;

ll n,m,seg[4*N],ans[N],num[N];
vector <ll> vc[N];
vector <pair<ll,ll> > vc2[N];

void update(ll q,ll xl,ll xr,ll id)
{
	if(xl>=xr)return ;
	seg[id]++;
	//cout<<xl<<" "<<xr<<" "<<seg[id]<<"\n";
	if(xl==xr-1)return ;
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,l);
	else update(q,mid,xr,r);
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	return query(ql,qr,xl,mid,l)+query(ql,qr,mid,xr,r);
}

int main() 
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d%d",&n,&m);
	while(n--)
	{
		ll lft,rght;
		scanf("%d%d",&lft,&rght);
		vc[rght].push_back(lft);
	}
	for(int i=0;i<m;i++)
	{
		ll cnt,lst=0;
		scanf("%d",&cnt);
		for(int j=0;j<cnt;j++)
		{
			ll x;
			scanf("%d",&x);
			vc2[x].push_back({i,lst});
			lst=x;
		}
		vc2[N-1].push_back({i,lst});
	}
	for(int i=0;i<N;i++)
	{
		if(i)num[i]=num[i-1];
		for(int j=0;j<vc2[i].size();j++)ans[vc2[i][j].first]+=query(0,vc2[i][j].second+1,0,N,1)-num[max(vc2[i][j].second-1,0)];
		for(int j=0;j<vc[i].size();j++)num[i]++,update(vc[i][j],0,N,1);
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}
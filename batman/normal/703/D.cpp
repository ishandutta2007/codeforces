#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef int ll;
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)1001*1000);
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);

ll n,m,a[N],xr[N],seg[4*N],ans[N];
vector <pair<ll,ll> > q[N];
map <ll,ll> last;

void update(ll q,ll xl,ll xr,ll id,ll num)
{
	if(xl>=xr)return ;
	if(xl==xr-1){seg[id]=num;return ;}
	ll mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,id*2,num);
	else update(q,mid,xr,id*2+1,num);
	seg[id]=seg[id*2]^seg[id*2+1];
	//cout<<xl<<" "<<xr<<" "<<seg[id]<<"\n";
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)
	{
		//cout<<xl<<" ||| "<<xr<<"\n";
		return seg[id];
			
	}
	ll mid=(xl+xr)/2;
	return query(ql,qr,xl,mid,id*2)^query(ql,qr,mid,xr,id*2+1);
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		xr[i]=xr[i-1]^a[i];
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		ll l,r;
		scanf("%d%d",&l,&r);
		q[r].push_back({l,i});
	}
	//cout<<query(4,6,0,N,1)<<"\n";
	//update(1,0,N,1,1);
	//cout<<query(4,6,0,N,1)<<"\n";
	for(int i=1;i<=n;i++)
	{
		update(i,0,N,1,a[i]);
		//cout<<i<<" ";
		if(last[a[i]]!=0)update(last[a[i]],0,N,1,0);
		last[a[i]]=i;
		//cout<<query(4,6,0,N,1)<<"\n";
		for(int j=0;j<q[i].size();j++)
		{
			//cout<<q[i][j].first<<" "<<i<<" ";
			//cout<<query(q[i][j].first,i+1,0,N,1)<<"\n";
			ans[q[i][j].second]=query(q[i][j].first,i+1,0,N,1)^xr[i]^xr[q[i][j].first-1];	
		}
		
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}
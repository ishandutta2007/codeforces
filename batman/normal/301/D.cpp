#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =201*1000;

ll n,m,id[N],fen[N],ans[N];
vector <ll> vec[N];
vector <pair<ll,ll> > sg[N];

void add(ll x){for(;x<=n;x+=x&-x)fen[x]++;}
ll query(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	scanf("%d%d",&n,&m);
   	for(int i=1;i<=n;i++)
   	{
   		ll ex;
		scanf("%d",&ex);
		id[ex]=i;	
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			vec[max(id[i],id[j])].push_back(min(id[i],id[j]));
	for(int i=0;i<m;i++)
	{
		ll l,r;
		scanf("%d%d",&l,&r);
		sg[r].push_back({l,i});
	}
	for(int i=1,all=0;i<=n;i++)
	{
		for(int j=0;j<vec[i].size();j++)add(vec[i][j]),all++;
		for(int j=0;j<sg[i].size();j++)ans[sg[i][j].second]=all-query(sg[i][j].first-1);
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}
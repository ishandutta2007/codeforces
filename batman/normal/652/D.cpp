#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e14);
const ll MOD=((ll)94573);
const ll N =201*1000;

ll n,fen[N],ans[N],num=1;
pair <pair<ll,ll>,ll> a[N];
map <ll,ll> mp;

ll query(ll x){ll cnt=0;for(int i=x;i>0;i-=i&(-i))cnt+=fen[i];return cnt;}

ll add(ll x){for(int i=x;i<=num;i+=i&(-i))fen[i]++;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first.first>>a[i].first.second;
		mp[a[i].first.second]=1;
		a[i].second=i;
	}
	for(map <ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
		if(it->second==1)
			it->second=num++;
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		//cout<<"hir";
		ans[a[i].second]=query(mp[a[i].first.second]);
		add(mp[a[i].first.second]);
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<"\n";
    return 0;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=1e9+7;
ll bit[500005],n;
pll arr[500005];
set<ll> s;

void modify(ll x,ll v)
{
	v=(v%MOD+MOD)%MOD;
	if(x==0) return;
	for(;x<=n;x+=x&-x) bit[x]=(bit[x]+v)%MOD;
}

ll query(ll x)
{
	ll re=0;
	for(;x;x-=x&-x) re=(re+bit[x])%MOD;
	return re;
}

int main()
{jizz
	ll ans=0;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i].F,arr[i].S=i;
	sort(arr+1,arr+n+1);
	
	modify(1,n);
	for(int i=1;i<=n;++i)
	{
		ll L,R;
		auto l=s.lower_bound(arr[i].S);
		if(l==s.end()) R=n-arr[i].S+1;
		else R=*l-arr[i].S;
		if(l==s.begin()) L=arr[i].S-1;
		else --l,L=arr[i].S-*l;
		s.insert(arr[i].S);
		modify(1,n-arr[i].S+1),modify(arr[i].S,-n+arr[i].S-1);
		modify(arr[i].S,-L),modify(arr[i].S+R,L);
		ans=(ans+query(arr[i].S)*arr[i].S%MOD*arr[i].F)%MOD;
		ans=(ans-arr[i].F*arr[i].S%MOD*(n-arr[i].S+1)%MOD+MOD)%MOD;
	}
	
	MEM(bit,0),s.clear();
	
	modify(1,n);
	for(int i=1;i<=n;++i)
	{
		arr[i].S=n-arr[i].S+1;
		ll L,R;
		auto l=s.lower_bound(arr[i].S);
		if(l==s.end()) R=n-arr[i].S+1;
		else R=*l-arr[i].S;
		if(l==s.begin()) L=arr[i].S-1;
		else --l,L=arr[i].S-*l;
		s.insert(arr[i].S);
		modify(1,n-arr[i].S+1),modify(arr[i].S,-n+arr[i].S-1);
		modify(arr[i].S,-L),modify(arr[i].S+R,L);
		ans=(ans+query(arr[i].S)*arr[i].S%MOD*arr[i].F)%MOD;
	}
	
	cout << ans << "\n";
}
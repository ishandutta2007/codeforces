#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<ll> p,v,rv;
bitset<64> prime;
ll arr[64];

ll po(ll a,ll n)
{
	ll re=1;
	for(;n;n>>=1,a*=a)
		if(n&1) re*=a;
	return re;
}

int main()
{jizz
	ll t,x,ans,l,r;
	for(int i=2;i<64;++i)
	{
		if(!prime[i]) p.pb(i);
		for(auto j:p)
		{
			if(i*j>=64) break;
			prime[i*j]=1;
			if(i%j==0) break;
		}
	}
	for(auto i:p)
		arr[i]=exp(log(3e18)/(double)i);
	for(int i=3;i<64;++i)
		for(int j=2;j<=arr[i];++j)
			v.pb(po(j,i));
	sort(ALL(v)),v.resize(unique(ALL(v))-v.begin());
	for(auto i:v)
	{
		x=(sqrt(i)+1e-9);
		if(x*x!=i) rv.pb(i);
	}
	cin >> t;
	while(t--)
	{
		cin >> x,ans=x-1;
		l=1,r=1e9;
		while(l<r)
		{
			ll m=(l+r)/2+1;
			if(m*m<=x) l=m;
			else r=m-1;
		}
		ans-=l-1;
		cout << ans-(upper_bound(ALL(rv),x)-rv.begin()) << "\n";
	}
}
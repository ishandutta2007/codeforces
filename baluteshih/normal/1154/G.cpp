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

const ll MAXC=10000000;
vector<ll> v;
ll fac[10000005],prime[10000005],ans=1e18;
pll rans,num[1000005];

void dfs(ll n,ll t,ll org)
{
	if(fac[n*t]&&fac[n*t]!=org)
	{
		if(num[org].F*num[fac[n*t]].F/n/t<ans)
			ans=num[org].F*num[fac[n*t]].F/n/t,rans=MP(num[org].S,num[fac[n*t]].S);
		return;
	}
	fac[n*t]=org;
	if(n==1) return;
	ll p=prime[n],cnt=0;
	while(n%p==0)
		n/=p,++cnt;
	for(int i=0;i<=cnt;++i)
		dfs(n,t,org),t*=p;
}

int main()
{jizz
	ll n;
	cin >> n;
	for(ll i=2;i<=MAXC;++i)
	{
		if(!prime[i]) v.pb(i),prime[i]=i;
		for(ll j:v)
		{
			if(i*j>MAXC) break;
			prime[i*j]=j;
			if(i%j==0) break;
		}
	}
	for(int i=1;i<=n;++i)
		cin >> num[i].F,num[i].S=i;
	sort(num+1,num+n+1);
	rans=MP(num[1].S,num[2].S),ans=num[1].F*num[2].F/__gcd(num[1].F,num[2].F);
	for(int i=1;i<=n;++i)
		dfs(num[i].F,1LL,i);
	if(rans.F<rans.S) cout << rans.F << ' ' << rans.S << "\n";
	else cout << rans.S << ' ' << rans.F << "\n";
}
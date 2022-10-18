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

bitset<200005> a,b;
ll sum[200005];
const ll MOD=998244353;

int main()
{jizz
	ll n,m,t=1,ans=0;
	cin >> n >> m >> a >> b;
	for(int i=m;i>=0;--i)
		sum[i]=sum[i+1]+b[i];
	for(int i=0;i<n;++i,t=t*2%MOD)
		if(a[i])
			ans=(ans+sum[i]*t)%MOD;
	cout << ans << "\n";
}
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

ll dp[1000005];
const ll MOD=998244353;

int main()
{jizz
	ll n;
	dp[1]=1;
	cin >> n;
	for(ll i=2,j=1;i<=n;j=j*i%MOD,++i)
	{
		dp[i]=(dp[i-1]+(j+MOD-1))%MOD*i%MOD;
	}
	cout << dp[n] << "\n";
}
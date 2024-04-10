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

ll arr[2005],pre[2005];
const ll MOD=100005;

int main()
{jizz
	ll n,s=0;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i],pre[i]=MOD+i-1-arr[i];
	for(int i=n;i>0;--i)
		pre[i]=(pre[i]-s+MOD)%MOD,s=(s+pre[i])%MOD;
	cout << n+1 << "\n";
	for(int i=1;i<=n;++i)
		cout << 1 << " " << i << " " << pre[i] << "\n";
	cout << 2 << " " << n << " " << MOD << "\n";
}
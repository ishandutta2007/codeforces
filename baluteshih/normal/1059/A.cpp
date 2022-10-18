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

int main()
{jizz
	ll n,l,a,ans=0,last=0,t,x;
	cin >> n >> l >> a;
	while(n--)
	{
		cin >> t >> x;
		ans+=(t-last)/a,last=t+x;
	}
	ans+=(l-last)/a;
	cout << ans << "\n";
}
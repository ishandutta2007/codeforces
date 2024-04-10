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

set<ll> s;
ll n;

void f(ll x)
{
	if(n==x) return s.insert(1),void();
	s.insert((2+(n/x-1)*x)*(n/x)/2);
}

int main()
{jizz
	cin >> n;
	for(ll i=1;i*i<=n;++i)
	{
		if(n%i) continue;
		f(i);
		if(i*i<n) f(n/i);
	}
	for(auto i:s)
		cout << i << " ";
	ET;
}
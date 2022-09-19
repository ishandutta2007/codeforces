#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> edge;

const int Maxn = 2e5 + 10;
ll Inf = 1e18;
const int Log = 20;
const ll Sqrt = 1000000;
const ll Mod = 998244353LL;

ll mul(ll a, ll b){
	a%=Mod;
	b%=Mod;
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n = 0;
	cin >> n;	
	if(n % 2 == 0) return cout << "NO\n", 0;
	if(n < 5) return cout << "NO\n", 0;
	//cout << "YES\n";
	cout << 1 << " " << (n - 3) / 2 << '\n';
	
	return 0;
}
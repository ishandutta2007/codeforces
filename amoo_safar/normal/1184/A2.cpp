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

bool ok[Maxn];
ll cnt[Maxn];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;	
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			memset(cnt, 0, sizeof cnt);
			for(int j = 0; j < n; j++){
				cnt[j % i] += (s[j] - '0');
			}
			ok[i] = true;
			for(int j = 0; j < i; j++) if(cnt[j] & 1) ok[i] = false;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(ok[__gcd((ll) i, n)]) ans ++;
	}
	cout << ans;
	return 0;
}
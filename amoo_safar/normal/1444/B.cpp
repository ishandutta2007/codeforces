// nemibinam invara kasi mesl khodemono !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 998244353;
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n + n; i++) cin >> a[i];
	sort(a, a + n + n);
	ll sm = 0;
	for(int i = 0; i <n; i++) sm -= a[i];
	for(int i = 0; i <n; i++) sm += a[n + i];
	sm %= Mod;
	// 	debug(sm);
	for(int i = 1; i <= n; i++) sm = mul(sm, inv(i));
	for(int i = 1; i <= n; i++) sm = mul(sm, n + i);
	sm += Mod;
	cout << sm % Mod << '\n';
	return 0;
}
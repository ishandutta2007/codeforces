// vaziat meshki-ghermeze !
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

const ld pi = acos(-1);
const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 20;

ll mul(ll a, ll b){ return (a * b) % Mod; }
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k, r, c;
	cin >> n >> m >> k >> r >> c;
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll pw = (n * m) - (r * c);
	if(pll(x1, y1) == pll(x2, y2))
		pw = (n * m);
	cout << bin_pow(k, pw) << '\n';
	return 0;
}
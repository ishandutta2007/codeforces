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

const ll Mod = 1000000007LL;
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, m;

pll bez(ll x, ll y, pll X, pll Y){
	if(x == 0) return Y;
	if(y == 0) return X;
	if(x > y) swap(x, y), swap(X, Y);
	ll d = y / x;
	y -= d * x;
	Y.F -= d * X.F;
	Y.S -= d * X.S;
	return bez(x, y, X, Y);
}
pll res = {0, 1};
ll Get(ll md_n, ll md_m){
	ll x = md_n * res.S * m + md_m * res.F * n;
	x %= (n * m);
	x += (n * m);
	return x % (n * m);
}
ll s1, s2, g;

ll Solve(int id1, int id2){
	ll md = id1 % g;
	if(id1 % g != id2 % g) return -1;
	id1 /= g;
	id2 /= g;
	ll res = Get(id1, id2);
	return md + res * g;
}

map<int, vector<int>> V;


ll a[N], b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll k;
	cin >> s1 >> s2 >> k;
	g = __gcd(s1, s2);
	n = s1 / g;
	m = s2 / g;
	// cin >> n >> m;
	res = bez(n, m, {1, 0}, {0, 1});
	// cout << res.F << ' ' << res.S << '\n';
	ll x;
	for(int i = 0; i < s1; i++){
		cin >> a[i];
		V[a[i]].pb(i);

	}
	for(int i = 0; i < s2; i++){
		cin >> a[i];
		V[a[i]].pb(i);
	}
	vector<ll> Col; 
	for(auto X : V){
		if(X.S.size() == 2){
			ll p = Solve(X.S[0], X.S[1]);
			if(p != -1)
				Col.pb(p);
		}
	}
	ll loop = n * m * g;

	sort(all(Col));
	// debug(Col.size());
	// debug(Col[0]);
	ll L = 0, R = Inf;
	ll mid;
	while(L + 1 < R){

		mid = (L + R) >> 1;
		ll fu = mid	/ loop;
		ll sm = fu * ((ll) Col.size());
		ll rq = mid % loop;
		for(auto x : Col) sm += (x < rq);
		if(mid - sm >= k) R = mid;
		else L = mid;
	}
	cout << R << '\n';
	// cout << Get(2, 6) << '\n';

	return 0;
}
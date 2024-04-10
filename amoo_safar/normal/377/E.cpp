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
const int N = 2e5 + 10;
const ll Inf = 1e18;
const ll Log = 30;

ll n, rq;

vector< pair<ll, pll> > V; // F.x + S

ll Inter(pll A, pll B){
	if(A.F == B.F)
		return A.S <= B.S ? -Inf : Inf;
	assert(B.F > A.F);
	return (A.S - B.S) / (B.F - A.F) + (0 < (A.S - B.S) % (B.F - A.F));
}
void Add(pll X){
	while(!V.empty() && Inter(V.back().S, X) <= V.back().F)
		V.pop_back();
	V.pb({ V.empty() ? -Inf : Inter(V.back().S, X) , X});
}
pll Get(pll Ln, ll X){
	ll h = Ln.S;
	assert(X >= h);
	ll x = (X - h + Ln.F - 1) / Ln.F;
	return {x, Ln.F * x + h};
}

pll Get(ll Y){ // Time Value
	assert(!V.empty());
	// auto it = -- upper_bound(all(V), pair<ll, pll>(X, {Inf, Inf}));
	// V.pb({Inf, {-1, -1}});
	int L = 0, R = V.size(), mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		if((Y - V[mid].S.S + (V[mid].S.F - 1)) / V[mid].S.F <= V[mid].F) R = mid;
		// if(Y - V[mid].S.S <= V[mid].F * V[mid].S.F) R = mid;
		else L = mid;
	}
	pll resL = Get(V[L].S, Y);
	pll resR = (R == (int) V.size() ? pll(Inf, -Inf) : Get(V[R].S, Y));
	if(resL.F != resR.F)
		return min(resL, resR);
	return max(resL, resR);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> rq;
	ll v, c;
	vector<pll> F;
	ll mx = 0;
	for(int i = 0; i < n; i++){
		cin >> v >> c;
		if(c == 0) mx = max(mx, v), Add({v, 0});
		else F.pb({v, c});
	}
	assert(!V.empty());

	sort(all(F));
	for(auto L : F){
		if(L.F <= mx) continue;
		pll res = Get(L.S);
		Add({L.F, res.S - L.S - res.F * L.F});
	}
	ll ans = Inf;
	for(auto X : V)
		ans = min(ans, Get(X.S, rq).F);
	cout << ans << '\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

ll manh(pll a, pll b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

pll fun(pll x, pll a, pll b){
	return pll(
		x.first * a.first + b.first,
		x.second * a.second + b.second
	);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	pll p, a, b, s;
	cin >> p.first >> p.second;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> s.first >> s.second;

	ll t;
	cin >> t;

	vector<pll> ls;

	while(max(abs(p.first),abs(p.second)) <= ll(2e16)+10){
		ls.push_back(p);
		p = fun(p,a,b);
	}

	int ans = 0;
	rep(i,0,sz(ls)) rep(j,i,sz(ls))
		if( manh(ls[i], ls[j]) + min(
			manh(s, ls[i]),
			manh(s, ls[j])
			) <= t){
		ans = max(ans, j-i+1);
	}
	cout << ans << endl;
}
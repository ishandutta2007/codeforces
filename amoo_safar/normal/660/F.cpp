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
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

struct CHT { // Min
	typedef pair<ll, ll> Line;
	#define M first
	#define H second

	vector< pair<ll, Line> > env;
	ll Inter(Line A, Line B){ // A.M >= B.M
		assert(A.M >= B.M);
		if(A.M == B.M)
			return (A.H <= B.H ? Inf : -Inf);
		return (B.H - A.H) / (A.M - B.M) + ((B.H - A.H) % (A.M - B.M) > 0);
	}
	void Add(Line A){
		while(!env.empty() && Inter(env.back().S, A) <= env.back().F)
			env.pop_back();
		env.pb({env.empty() ? -Inf : Inter(env.back().S, A), A});
	}
	ll Get(ll x){
		auto it = --upper_bound(all(env), pair<ll, Line>(x, {Inf, Inf}));
		return it->S.M * x + it->S.H; 
	}
};
CHT cht;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// test.Add({1, 0});
	// cout << test.Get(10) << '\n';
	// test.Add({0, 3});
	// cout << test.Get(2) << ' ' << test.Get(4) << '\n';
	int n;
	cin >> n;
	ll sm = 0;
	ll sm2 = 0;
	cht.Add({0, 0});
	ll x, ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> x;
		x = -x;

		sm += x;
		sm2 += x * i;
		cht.Add({-i, i * sm - sm2});
		ans = min(ans, sm2 + cht.Get(sm));
	}
	cout << -ans << '\n';
	return 0;
}
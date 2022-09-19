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
CHT test;

CHT seg[N << 2];

pll A[N];

void Build(int id, int L, int R){
	if(L + 1 == R){
		seg[id].Add(A[L]);
		return ;
	}
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);
	vector<pll> V;
	for(auto x : seg[id << 1].env) V.pb(x.S);
	for(auto x : seg[id << 1 | 1].env) V.pb(x.S);
	sort(all(V));
	reverse(all(V));
	for(auto ln : V)
		seg[id].Add(ln);
	return ;
}

ll Get(int id, int l, int r, ll x, int L, int R){
	if(r <= L || R <= l) return Inf;
	if(l <= L && R <= r) return seg[id].Get(x);
	int mid = (L + R) >> 1;
	return min(Get(id << 1, l, r, x, L, mid),
			Get(id << 1 |1, l, r, x, mid, R));
}

ll a[N], ps[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// test.Add({1, 0});
	// cout << test.Get(10) << '\n';
	// test.Add({0, 3});
	// cout << test.Get(2) << ' ' << test.Get(4) << '\n';
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
		A[i] = {a[i], i * a[i] - ps[i]};
	}
	Build(1, 1, n + 1);

	int q;
	cin >> q;
	int x, y;
	for(int i = 0; i < q; i++){
		cin >> y >> x;
		cout << Get(1, x - y + 1, x + 1, y - x, 1, n + 1) + ps[x] << '\n';
	}
	return 0;
}
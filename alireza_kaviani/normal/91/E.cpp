#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define lc 							id << 1
#define rc							lc | 1

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool Q = 1;
struct Line {
	mutable ll k, m, p, ind;
	bool operator<(const Line& o) const { return Q ? k < o.k : p < o.p; }
};
 
struct CHT : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m , ll ind) {
		auto z = insert({k, m, 0 , ind}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	pll query(ll x) {
		assert(!empty());
		Q = 0 ; auto l = *lower_bound({0 , 0 , x , 0}); Q = 1;
		return pll(l.k * x + l.m , l.ind);
	}
};

int n , q , A[MAXN] , B[MAXN];
CHT seg[MAXN << 2];

void build(int id = 1 , int l = 1 , int r = n + 1){
	for(int i = l ; i < r ; i++){
		seg[id].add(B[i] , A[i] , i);
	}
	if(r - l == 1)	return;
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
}

pll get(int ql , int qr , int time , int id = 1 , int l = 1 , int r = n + 1){
	if(qr <= l || r <= ql)	return {-INF , -INF};
	if(ql <= l && r <= qr)	return seg[id].query(time);
	int mid = l + r >> 1;
	return max(get(ql , qr , time , lc , l , mid) , get(ql , qr , time , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i] >> B[i];
	}
	build();
	while(q--){
		int l , r , t;
		cin >> l >> r >> t;
		cout << get(l , r + 1 , t).Y << endl;
	}

    return 0;
}
/*

*/
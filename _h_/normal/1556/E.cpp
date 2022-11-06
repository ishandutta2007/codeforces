#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll inf = 1e16;

struct Tree {
	// first min, then max, then maxdif
	typedef tuple<ll, ll, ll> T;
	static constexpr T unit = {inf, -inf, 0};
	T f(T a, T b) { 
		return { 
			min(get<0>(a), get<0>(b)),
			max(get<1>(a), get<1>(b)),
			max(get<2>(a), max(get<2>(b), get<1>(b) - get<0>(a)))
		};
	} 
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, q;
	cin >> n >> q;

	vector<ll> pre(n+1);

	for(int sg = 1; sg >= -1; sg -= 2) rep(i,0,n){
		int a;
		cin >> a;
		pre[i+1] -= a * sg;
	}
	rep(i,0,n) pre[i+1] += pre[i];

	Tree tree(n+1);
	rep(i,0,n+1) tree.update(i, {pre[i], pre[i], 0});
	
	rep(_,0,q){
		int l, r;
		cin >> l >> r;
		auto res = tree.query(l-1, r);
		if(pre[l-1] != pre[r] || get<0>(res) < pre[l-1]){
			cout << -1 << endl;
		} else cout << get<2>(res) << endl;
	}
}
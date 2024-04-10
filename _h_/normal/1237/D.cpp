// written by aitch
// on 2019 10/16 at 15:35:00
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
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

	int n;
	cin >> n;

	vi a(n);
	trav(x, a) cin >> x;

	int m = 3*n;
	vi c(m);
	rep(i,0,3) rep(j,0,n) c[i*n + j] = a[j];

	Tree st(m);
	rep(i,0,m) st.update(i, c[i]);

	vi mn(m, m);

	rep(i,0,m){
		int lo = -1, hi = i;
		while(lo+1 < hi){
			int mi = (lo + hi)/2;
			if( st.query(mi, i) > 2*c[i] )
				lo = mi;
			else
				hi = mi;
		}
		if(lo > -1){
			mn[lo] = min(mn[lo], i);
		}
	}

	rrep(i,1,m) mn[i-1] = min(mn[i-1], mn[i]);

	rep(i,0,n){
		if(mn[i] == m) cout << -1 << ' ';
		else cout << mn[i]-i << ' ';
	}
	cout << endl;
}
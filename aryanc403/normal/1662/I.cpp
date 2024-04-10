#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Node {
    using T = ll;
    T unit = 0;
    T f(T a, T b) { return max(a, b); }
 
    Node *l = 0, *r = 0;
    ll lo, hi;
    T madd = 0;
    T val = unit;
    Node(ll _lo,ll _hi):lo(_lo),hi(_hi){}
    T query(ll L, ll R) {
        if (R <= lo || hi <= L) return unit;
        if (L <= lo && hi <= R) return val;
        push();
        return f(l->query(L, R), r->query(L, R));
    }
    void add(ll L, ll R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = f(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            ll mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> p(n);
	for (int &x : p) cin >> x;
	vector<int> x(m);
	for (int &a : x) cin >> a;
	sort(begin(x), end(x));

	vector<int> closest(n, INT_MAX);
	for (int i = 0; i < n; ++i) {
		int pos = 100 * i;
		auto it = lower_bound(begin(x), end(x), pos);
		if (it != end(x)) {
			closest[i] = *it - pos;
		}
		if (it != begin(x)) {
			--it;
			closest[i] = min(closest[i], pos - *it);
		}
	}

	const int LIM = 2e9 + 15;
	Node *tr = new Node(0, LIM);
	for (int i = 0; i < n; ++i) {
		if (closest[i] == i*100) continue;
		int left = i*100 - closest[i];
		int right = i*100 + closest[i];
		if (left == 0) tr -> add(0, 2*right, p[i]);
		else tr -> add(2*left + 1, 2*right, p[i]);
		// cout << 2*left+1 << ": " << 2*right << ' ' << '\n';
		// tr -> add(2*left + 1, 2*right, p[i]);
	}
	// int mx = 0;
	// for (int i = 0; i <= 500; ++i) cout << tr -> query(i, i+1) << ' ';
	// cout << mx << '\n';
	cout << tr -> query(0, LIM) << '\n';
}
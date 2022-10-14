/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
	cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
	while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
	return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
	return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
	bool is = false;
	for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
	return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
	vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
	vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
	vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
	vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 80000;
#define pll pair <lli, lli>

void upd (pll &i, pll j) {
	i.X = min(i.X, j.X);
	i.Y = max(i.Y, j.Y);
}

struct Seg {
	int l, r, m;
	lli mn, mx;
	Seg* ch[2];
	Seg (int _l, int _r, vector <lli> &a) : l(_l), r(_r), m(l + r >> 1) {
		if (r - l > 1) {
			ch[0] = new Seg(l, m, a);
			ch[1] = new Seg(m, r, a);
			pull();
		} else {
			mx = mn = a[l];
		}
	}
	void pull() {
		mn = min(ch[0]->mn, ch[1]->mn);
		mx = max(ch[0]->mx, ch[1]->mx);
	}
	pll query(int a, int b) {
		if (a <= l && r <= b) return mp(mn, mx);
		pll ans = mp(1ll << 60, -1ll << 60);
		if (a < m) upd(ans, ch[0]->query(a, b));
		if (m < b) upd(ans, ch[1]->query(a, b));
		return ans;
	}
};

int main () {
	owo;
	int n, q;
	cin >> n >> q;
	vector <lli> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector <lli> pre = {0};
	for (int i = 0, x; i < n; ++i) {
		cin >> x, a[i] -= x;
		pre.pb(pre.back() + a[i]);
	}
	Seg root(0, n, pre);
	while (q--) {
		int l, r;
		cin >> l >> r, --l;
		if (pre[l] != pre[r]) cout << -1 << endl;
		else {
			pll res = root.query(l, r);
			if (res.Y > pre[l]) cout << -1 << endl;
			else cout << pre[l] - res.X << endl;
		}
	}
}
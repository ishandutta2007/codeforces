#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }

template <class T>
struct node {
	static const T neutral = mod;
	T val = neutral, p = 0;
	int ind = 0;
	node() {}
	node(T val) : val(val) {} 
	void upd(T x) { val += x, p += x; }
	void upd(const node &t) { upd(t.p); }
	bool updated() const { return p != 0; }
	void unupdate() { p = 0;}
};

template <class T>
node<T> merge(const node<T> &a, const node<T> &b) {
	node<T> ans;
	if (a.val <= b.val) ans.val = a.val, ans.ind = a.ind;
	else ans.val = b.val, ans.ind = b.ind;
	return ans;
}

template<class node, node (*merge)(const node&, const node&) = merge>
struct Tree {
	int n = 1;
	vector<node> t;
	node& operator[](int ind) { return t[ind + n]; }  // finalize() to used with pushes
	const node& operator[](int ind) const { return t[ind + n]; }  // finalize() to used with pushes
	void submerge(int v) {  // merge v's sons to v
		if (v >= n) return;
		t[v] = merge(t[v + v], t[v + v + 1]);
	}
	void resize(int sz) {  // allocation
		while (n < sz) n <<= 1;
		t.resize(2 * n);
	}
	void blank() {  // default values
		for (int v = 0; v < 2 * n; v++)
			t[v] = node();
	}
	void build() {  // calculate middle nodes
		for (int i = n - 1; i > 0; i--)
			submerge(i);
	}
	template<class T>
	void assign(const vector<T> &a) {  // copy of a
		resize(a.size());
		for (int i = 0; i < a.size(); i++)
			t[i + n] = a[i];
		for (int i = a.size(); i < n; i++)
			t[i + n] = node();
		build();
	}
	Tree() {} // empty
	Tree(int sz) { resize(sz); blank(); } // size, default values
	template<class T> Tree(const vector<T> &a) { assign(a); } // copy of a
	template<class T>
	void updup(int i, const T &val) { // upd at i with val, doesn't support push
		i += n;
		t[i].upd(val);
		for (i >>= 1; i > 0; i >>= 1)
			submerge(i);
	}
	node getup(int l, int r) { // get at [l, r), doesn't support push
		l += n, r += n;
		int cr = r;
		node left, right;
		bool lf = true, rf = true;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) left = lf ? lf = false, t[l++] : merge(left, t[l++]);
			if (r & 1) right = rf ? rf = false, t[--r] : merge(t[--r], right);
		}
		if (lf) return right;
		if (rf) return left;
		return merge(left, right);
	}
	void push(int v) {
		if (v >= n) return;
		if (t[v].updated()) {
			t[v + v].upd(t[v]);
			t[v + v + 1].upd(t[v]);
			t[v].unupdate();
		}
	}
	void finalize() { for (int v = 1; v < n; v++) push(v); }
	// update [l, r) with value x, supports push
	template<class T>
	void upd(int l, int r, const T &x, int v, int vl, int vr) { 
		if (vl >= r || vr <= l) return;
		if (vl >= l && vr <= r) return t[v].upd(x);
		push(v);
		int vm = vl + vr >> 1;
		upd(l, r, x, v + v, vl, vm);
		upd(l, r, x, v + v + 1, vm, vr);
		submerge(v);
	}
	template<class T>
	void upd(int l, int r, const T &x) { upd(l, r, x, 1, 0, n); } 
	
	// get at [l, r), supports push
	node get(int l, int r, int v, int vl, int vr) {
		if (r <= vl || vr <= l) return node();
		if (l <= vl && vr <= r) return t[v];
		push(v);
		int vm = vl + vr >> 1;
		if (r <= vm) return get(l, r, v + v, vl, vm);
		if (l >= vm) return get(l, r, v + v + 1, vm, vr);
		return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
	}
	node get(int l, int r) { return get(l, r, 1, 0, n); } 

	void show() {
		cout << "TREE:\n";
		auto frst = [](int i){ return (i & (i - 1)) == 0; };
		for (int i = 1; i < 2 * n; i++) {
			if (frst(i)) cout << "l: ";
			if (t[i].val != node::neutral)
				cout << "\t{" << t[i].val << ' ' << t[i].p << "}";
			else
				cout << "\t{" << "_" << ' ' << t[i].p << "}";
			if (frst(i + 1)) cout << endl;
		}
		cout << "----\t----\t----\t----" << endl;
	}
};

bool viv = false;
int n;
vector<int> v;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;


	vector<vector<int>> pl(n);
	for (int i = 0; i < n; i++) {
		pl[v[i]].push_back(i);
	}
	vector<pii> seg;

	int nans = 0;
	for (int i = 0; i < n; i++) {
		if (pl[i].size() >= 1) {
			seg.push_back({pl[i][0], pl[i].back()});
		}
		nans += max((int)pl[i].size() - 2, 0);
	}

	vector<int> ans(n + 1, mod);
	ans[0] = 0;
	Tree<node<int>> t;
	t.assign(ans);

	sort(seg.begin(), seg.end());

	for (auto p : seg) {
		int l = p.F + 1;
		int r = p.S + 1;
		int ans1 = t.get(l - 1, l).val + 1 + (l != r);
		int ans2 = t.get(l + 1, r).val + 1;

		ans1 = min(ans1, ans2);

		int val = t.get(r, r + 1).val;
		t.upd(r, r + 1, ans1 - val);

		if (viv) {
			cout << "put " << ans1 << " to " << r << endl;
			t.show();
		}
	}

	// for (auto p : seg) {
	// 	int l = p.F;
	// 	int r = p.S;
	// 	// if (t.get(l, l + 1).val > 0)
	// 	// 	nans++;
	// 	if (l != r)
	// 		if (t.get(r, r + 1).val > 0)
	// 			nans++;
	// 	t.upd(l + 1, r, 1);
	// }
	// for (auto p : seg) {
	// 	int l = p.F;
	// 	int r = p.S;
	// 	if (t.get(l, l + 1).val > 0)
	// 		nans++;
	// 	// if (l != r)
	// 	// 	if (t.get(r, r + 1).val > 0)
	// 	// 		nans++;
	// }


	// for (auto p : seg) {
	// 	int l = p.F + 1;
	// 	int r = p.S + 1;
	// 	if (viv)
	// 		cout << "see " << l << ' ' << r << endl;

	// 	int best = t.getup(0, l).val;
	// 	int best2 = t.getup(0, n + 1).val - 1;
	// 	best = max(best, best2);

	// 	int val = best + (r - l - 1);
	// 	t.updup(r, val);
	// 	if (viv)
	// 		cout << "\tput " << val << " to " << r << endl;
	// }
	// int res = t.getup(0, n + 1).val;

	int res = t.get(n, n + 1).val;
	res = n - res;
	cout << res << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}
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

ifstream in;
ofstream out;


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


bool viv = false;


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


template <class T>
struct node2 {
	static const T neutral = 0;
	T val = neutral, p = 0;
	int ind = 0;
	node2() {}
	node2(T val) : val(val) {} 
	void upd(T x) { val += x, p += x; }
	void upd(const node2 &t) { upd(t.p); }
	bool updated() const { return p != 0; }
	void unupdate() { p = 0;}
};

template <class T>
node2<T> merge2(const node2<T> &a, const node2<T> &b) {
	node2<T> ans;
	ans = a;
	ans.val += b.val;
	ans.p = 0;
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


// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> table;
// using my_map = gp_hash_table<int, int>;

// using my_map = map<int, int>;

int n, m;
vector<int> a, b, v, sv;
// my_map mp;

vector<vector<int>> pla;
vector<int> cntb;

inline int pl(int val) {
	return lower_bound(sv.begin(), sv.end(), val) - sv.begin();	
}

void prepare() {
	// set<int> s;
	// for (auto i : v)
	// 	s.insert(i);

	int c = 0;
	sv.clear();
	pla.clear();
	cntb.clear();
	for (int i = 0; i < v.size(); i++) {
		if (i == 0 || v[i] != v[i - 1])
			sv.push_back(v[i]);
	}
	// for (auto val : s) {
	// 	sv.push_back(val);
	// }

	pla.resize(sv.size());
	for (int i = 0; i < a.size(); i++)
		pla[pl(a[i])].push_back(i);
	cntb.resize(sv.size());
	for (auto val : b) {
		cntb[pl(val)]++;
	}
}

void work() {
	Tree<node<int>> t;

	vector<int> init(a.size() + 1);
	iota(init.begin(), init.end(), 0);
	t.assign(init);

	ll old = 0;
	ll ans = 0;
	for (int i = 0; i < sv.size(); i++) {
		for (auto pl : pla[i])
			t.upd(pl + 1, a.size() + 1, -1);
		ll res = t.get(0, a.size() + 1).val;
		ans += cntb[i] * (old + res);
		for (auto pl : pla[i]) {
			t.upd(pl + 1, a.size() + 1, -1);
			old++;
		}
	}

	Tree<node2<int>, merge2> t2;
	vector<int> init2(sv.size() + 1, 0);
	t2.assign(init2);

	ll ans2 = 0;
	for (auto val : a) {
		ll add = t2.getup(pl(val) + 1, sv.size() + 1).val;
		// ll add = t2.get(mp[val] + 1, sv.size() + 1).val;
		ans2 += add;
		t2.updup(pl(val), 1);
		// t2.upd(mp[val], mp[val] + 1, 1);
	}

	cout << ans + ans2 << ' ';
}

void solve() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	b.resize(m);
	for (auto &i : b)
		cin >> i;

	v = a;
	for (auto i : b)
		v.push_back(i);
	sort(v.begin(), v.end());

	prepare();
	// if (n + m > 100 * kk)
	// 	return;
	work();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}
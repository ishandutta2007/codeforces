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

template <class T>
struct node {
	static const T neutral = -mod;
	T val = 0, p = 0;
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
	ans.val = a.val + b.val;
	// if (a.val >= b.val) ans.val = a.val, ans.ind = a.ind;
	// else ans.val = b.val, ans.ind = b.ind;
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
int n, q;
vector<int> vals;
vector<vector<int>> e;
vector<vector<vector<int>>> qr;
vector<int> ans;

vector<int> cnt;
vector<set<int>> who;
Tree<node<int>> t;

void del(int val) {
	who[cnt[val]].erase(val);
	// t.upd(cnt[val], cnt[val] + 1, -1);
	t.updup(cnt[val], -1);
}

void add(int val) {
	who[cnt[val]].insert(val);
	// t.upd(cnt[val], cnt[val] + 1, 1);
	t.updup(cnt[val], 1);
}

void ch(int val, int c) {
	del(val);
	cnt[val] += c;
	add(val);
}

int get_ans(int l, int k) {
	if (viv) {
		cout << "get_ans(" << l << ' ' << k << ")" << endl;
		cout << "cnt = ";
		for (auto i : cnt)
			cout << i << ' ';
		cout << endl;
		for (int i = 0; i < who.size(); i++) {
			cout << "who[" << i << "] = ";
			for (auto v : who[i])
				cout << v << ", ";
			cout << endl;
		}
		t.show();
	}
	int all = t.getup(l, n + 1).val;
	if (all < k)
		return -1;

	int lb = l;
	int rb = n + 1;
	while (lb + 1 < rb) {
		int m = lb + rb >> 1;
		if (t.getup(l, m).val < k)
			lb = m;
		else
			rb = m;
	}
	if (viv)
		cout << "lb, rb = " << lb << ", " << rb << endl;
	assert(who[lb].size());
	return (*who[lb].begin()) + 1;
}

void work(int v) {
	ch(vals[v], 1);
	for (auto vec : qr[v]) {
		int l, k, num;
		l = vec[0];
		k = vec[1];
		num = vec[2];
		ans[num] = get_ans(l, k);
	}

	for (auto u : e[v])
		work(u);
	ch(vals[v], -1);
}

void solve() {
	cin >> n >> q;
	vals.resize(n);
	for (auto &i : vals)
		cin >> i, i--;

	cnt.assign(n, 0);
	who.assign(n + 1, {});
	for (int i = 0; i < n; i++)
		who[cnt[i]].insert(i);
	vector<int> sz(n + 1);
	for (int i = 0; i < sz.size(); i++)
		sz[i] = who[i].size();
	t.assign(sz);

	e.assign(n, {});
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p, p--;
		// e[i].puh_back(p);
		e[p].push_back(i);
	}

	qr.assign(n, {});
	for (int i = 0; i < q; i++) {
		int v, l, k;
		cin >> v >> l >> k;
		v--;
		qr[v].push_back({l, k, i});		
	}

	ans.resize(q);
	work(0);
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
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
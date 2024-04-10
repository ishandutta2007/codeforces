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
int n;
vector<int> v;


template <class T>
struct node {
	static const T neutral = inf;
	T val = neutral, p = 0;
	int cnt = 1;
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
	if (a.val <= b.val){ 
		ans.val = a.val, ans.ind = a.ind, ans.cnt = a.cnt;
		if (b.val == a.val)
			ans.cnt += b.cnt;
	}
	else ans.val = b.val, ans.ind = b.ind, ans.cnt = b.cnt;
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
		for (int i = 0; i < a.size(); i++) {
			t[i + n] = a[i];
			t[i + n].ind = i;
		}
		for (int i = a.size(); i < n; i++) {
			t[i + n] = node();
			t[i + n].ind = a.size();			
		}
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

	// get at [l, r), supports push
	node get_neg(int l, int r, int v, int vl, int vr) {
		// cout << "get_neg(" << l << ' ' << r << ' ' << v << ' ' << vl << ' ' << vr << ")" << endl;
		if (r <= vl || vr <= l) return node();
		if (l <= vl && vr <= r)
			if (t[v].val >= 0 || vl + 1 == vr)
				return t[v];
		push(v);
		int vm = vl + vr >> 1;
		if (r <= vm) return get_neg(l, r, v + v, vl, vm);
		if (l >= vm) return get_neg(l, r, v + v + 1, vm, vr);
		auto res = get_neg(l, r, v + v, vl, vm);
		if (res.val >= 0)
			res = get_neg(l, r, v + v + 1, vm, vr);
		return res;
	}
	node get_neg(int l, int r) {return get_neg(l, r, 1, 0, n); } 

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

ll solver(int tp) {
	Tree<node<ll>, merge> teven;
	Tree<node<ll>, merge> todd;
	vector<ll> z((n + 1) / 2);
	teven.assign(z);
	todd.assign(z);

	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (viv)
			cout << "iter " << i << endl;
		ll val = v[i];
		int me = i / 2;
		int pr = (i - 1) / 2;
		int nx = (i + 1) / 2;
		int lans = 0;

		if (i & 1) {
			todd.upd(me, n / 2, val);
			teven.upd(nx, (n + 1) / 2, -val);
			if (viv) {
				teven.show();
				todd.show();
			}

			auto srodd = todd.get_neg(me, n / 2);
			auto sreven = teven.get_neg(nx, (n + 1) / 2);
			if (viv) {			
				cout << srodd.val << ' ' << srodd.cnt << ' ' << srodd.ind << endl;
				cout << sreven.val << ' ' << sreven.cnt << ' ' << sreven.ind << endl;
			}
			int fodd = srodd.ind;
			int feven = sreven.ind;
			if (viv)
				cout << "see " << fodd << ' ' << feven << endl;

			if (srodd.val >= 0)
				fodd = n / 2;
			if (sreven.val >= 0)
				feven = (n + 1) / 2;

			int plodd = min(fodd, feven);
			int pleven = min(feven, fodd + 1);

			auto resodd  = todd.get(me, plodd);
			auto reseven = teven.get(nx, pleven);
			if (viv) {
				cout << "[" << me << ' ' << pleven << ")" << endl;
				cout << "[" << nx << ' ' << plodd << ")" << endl;
				cout << resodd.val << ' ' << resodd.cnt << ' ' << resodd.ind << endl;
				cout << reseven.val << ' ' << reseven.cnt << ' ' << reseven.ind << endl;
			}
			assert(resodd.val >= 0);
			assert(reseven.val >= 0);
			if (resodd.val == 0)
				lans += resodd.cnt;
			if (reseven.val == 0)
				lans += reseven.cnt;
		} else {
			teven.upd(me, (n + 1) / 2, val);
			todd.upd(nx, n / 2, -val);

			auto sreven = teven.get_neg(me, (n + 1) / 2);
			auto srodd = todd.get_neg(nx, n / 2);
			int feven = sreven.ind;
			int fodd = srodd.ind;

			if (sreven.val >= 0)
				feven = (n + 1) / 2;
			if (srodd.val >= 0)
				fodd = n / 2;

			int pleven = min(feven, fodd + 1);
			int plodd = min(fodd, feven);

			auto reseven = teven.get(me, pleven);
			auto resodd  = todd.get(nx, plodd);
			if (viv) {
				cout << "[" << me << ' ' << pleven << ")" << endl;
				cout << "[" << nx << ' ' << plodd << ")" << endl;
				cout << reseven.val << ' ' << reseven.cnt << ' ' << reseven.ind << endl;
				cout << resodd.val << ' ' << resodd.cnt << ' ' << resodd.ind << endl;
			}
			assert(reseven.val >= 0);
			assert(resodd.val >= 0);
			if (reseven.val == 0)
				lans += reseven.cnt;
			if (resodd.val == 0)
				lans += resodd.cnt;
		}
		ans += lans;
		if (viv) {
			teven.show();
			todd.show();
			cout << "\n\n";
			cout << "ADD " << lans << endl;
			cout << "\n\n\n\n\n";
		}
	}
	return ans;	
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	ll ans = 0;
	ans += solver(0);
	// ans += solver(1);

	cout << ans << '\n';

	if (viv)
		cout << "\n\n\n\n\n";
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
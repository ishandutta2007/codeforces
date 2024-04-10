#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
//typedef long long   int;
typedef long double ld;
typedef pair<int, int> pint;
 
// ifstream in;
// ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 1;
const long long inf = ml * ml * ml + 7;
 
 
int n, i, j;
vector<pint> m;
vector<int> bal, p;
bool viv = false;
 
struct Tree {
	int s = 1;
	int n = 0;
	int my_nuint = 0; // sum
	vector<pint> t;
	vector<pint> seg;
 
	void upd(long long v);
	void push(long long v);
 
	inline int res(int v1, int v2) { // sum
		return v1 + v2;
	}
 
	void cnt_seg() {
		seg.resize(2 * s);
		seg[1] = {0, s};
		for (int i = 1; i < s; i++) {
			int tm = seg[i].F + seg[i].S >> 1;
			seg[2 * i] = {seg[i].F, tm};
			seg[2 * i + 1] = {tm, seg[i].S};
		}
	}
 
	void build(int sz) {
		n = sz;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_nuint, my_nuint});
		cnt_seg();
	}
 
	void build(vector<int> v) {
		n = v.size();
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_nuint, my_nuint});
		for (int i = 0; i < n; i++)
			t[s + i] = {v[i], my_nuint};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}
 
 
 
	void upd(int v) {
		if (v >= s)
			return;
		t[v].F = res(t[2 * v].F, t[2 * v + 1].F);
	}
 
	void push(int v) {
		if (v >= s)
			return;
		int p = t[v].S;
		if (p == my_nuint)
			return;
		t[v].S = my_nuint;
		t[2 * v].S = p;
		t[2 * v + 1].S = p;
		t[2 * v].F = res(t[2 * v].F, p);
		t[2 * v + 1].F = res(t[2 * v + 1].F, p);
	}
 
	void tree_add(int v, int val) { // sum
		t[v].F += val * (seg[v].S - seg[v].F);
		t[v].S = res(t[v].S, val);
	}
 
 
 
	int val(int l, int r, int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return my_nuint;
		push(v);
		if (l <= tl && tr <= r) 
			return t[v].F;
		int tm = tl + tr >> 1;
		int v1 = val(l, r, 2 * v, tl, tm);
		int v2 = val(l, r, 2 * v + 1, tm, tr);
		upd(v);
		return res(v1, v2);
	}
 
	void add(int l, int r, int v, int tl, int tr, int val) {
		if (r < tl || tr < l)
			return;
		push(v);
		if (l <= tl && tr <= r) {
			tree_add(v, val);
			return;
		}
		int tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
	}
 
 
 
	int val(int l, int r) {
		return val(l, r + 1, 1, 0, s);
	}
 
	void add(int v, int val) {
		v += s;
		while (v)
			t[v].F = res(t[v].F, val), v >>= 1;
	}
 
	void add(int l, int r, int t) {
		add(l, r + 1, 1, 0, s, t);
	}
 
	void show() {
		for (int i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};
 
struct Tree_max {
	int s = 1;
	int n = 0;
	int my_nuint = -mod; // sum
	vector<pint> t;
	vector<pint> seg;
 
	inline int res(int v1, int v2) { // sum
		return max(v1, v2);
	}
 
	void cnt_seg() {
		seg.resize(2 * s);
		seg[1] = {0, s};
		for (int i = 1; i < s; i++) {
			int tm = seg[i].F + seg[i].S >> 1;
			seg[2 * i] = {seg[i].F, tm};
			seg[2 * i + 1] = {tm, seg[i].S};
		}
	}
 
	void build(int sz) {
		n = sz;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_nuint, my_nuint});
		cnt_seg();
	}
 
	void build(vector<int> v) {
		n = v.size();
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_nuint, my_nuint});
		for (int i = 0; i < n; i++)
			t[s + i] = {v[i], my_nuint};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}
 
 
 
	void upd(int v) {
		if (v >= s)
			return;
		t[v].F = res(t[2 * v].F, t[2 * v + 1].F);
	}
 
	void push(int v) {
		if (v >= s)
			return;
		int p = t[v].S;
		if (p == my_nuint)
			return;
		t[v].S = my_nuint;
		t[2 * v].S = p;
		t[2 * v + 1].S = p;
		t[2 * v].F = res(t[2 * v].F, p);
		t[2 * v + 1].F = res(t[2 * v + 1].F, p);
	}
 
	void tree_add(int v, int val) { // sum
		// t[v].F += val * (seg[v].S - seg[v].F);
		t[v].F = res(t[v].S, val);
		t[v].S = res(t[v].S, val);
	}
 
 
 
	int val(int l, int r, int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return my_nuint;
		push(v);
		if (l <= tl && tr <= r) 
			return t[v].F;
		int tm = tl + tr >> 1;
		int v1 = val(l, r, 2 * v, tl, tm);
		int v2 = val(l, r, 2 * v + 1, tm, tr);
		upd(v);
		return res(v1, v2);
	}
 
	void add(int l, int r, int v, int tl, int tr, int val) {
		if (r <= tl || tr <= l)
			return;
		push(v);
		if (l <= tl && tr <= r) {
			tree_add(v, val);
			return;
		}
		int tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
	}
 
 
 
	int val(int l, int r) {
		return val(l, r + 1, 1, 0, s);
	}
 
	void add(int v, int val) {
		v += s;
		while (v)
			t[v].F = res(t[v].F, val), v >>= 1;
	}
 
	void add(int l, int r, int t) {
		add(l, r + 1, 1, 0, s, t);
	}
 
	void show() {
		for (int i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};
 
 
Tree t;
void bad() {
	cout << "NO\n";
	exit(0);
}

void connected() {
	vector<pint> v;
	for (auto p : m)
		v.push_back({p.S, p.F});
	sort(v.rbegin(), v.rend());
	Tree_max lt;
	Tree sum;
	lt.build(2 * v.size());
	sum.build(2 * v.size());
	for (auto &p : v)
		swap(p.F, p.S);
	reverse(m.begin(), m.end());
	for (auto p : m) {
		lt.add(p.F, p.S);
		sum.add(p.F, 1);
		sum.add(p.S, 1);
		vector<int> vec;
		int res = p.S;
		while (vec.size() < 4 || vec[vec.size() - 1] != vec[vec.size() - 2]) {
			res = lt.val(p.F, res);
			vec.push_back(res);
		}
		// cout << "On " << p.F << ' ' << p.S << " have " << res << endl;
		if (vec.back() != 2 * m.size() - 1 && sum.val(p.F, res) == res + 1 - p.F)
			bad();

		lt.add(p.F, res);
		lt.add(p.S, res);
	}
	reverse(m.begin(), m.end());
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    bal.resize(2 * n + 1);
    for (i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        bal[a]++;
        bal[b]--;
        m.push_back({a, b});
    }
   	sort(m.begin(), m.end());

   	connected();

   	Tree is;
   	Tree ot;
   	is.build(2 * n);
   	ot.build(2 * n);
   	for (auto i : m) {
   		is.add(i.F, 1);
   		ot.add(i.S, 1);
   	}
   	long long ans = 0;
   	for (auto p : m) {
   		int res = is.val(p.F + 1, p.S - 1);
   		res -= ot.val(p.F + 1, p.S - 1);
   		ans += res;
   		is.add(p.F, -1);
   		ot.add(p.S, -1);
   	}
   	if (ans != n - 1)
   		bad();
   	cout << "YES\n";
    return 0;
}
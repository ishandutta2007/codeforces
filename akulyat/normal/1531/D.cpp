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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;

map<string, int> num;
map<int, string> str;

void prepare() {
	int k = 0;
	num["lock"] = k++;
	num["unlock"] = k++;
	num["blue"] = k++;
	num["red"] = k++;
	num["orange"] = k++;
	num["yellow"] = k++;
	num["green"] = k++;
	num["indigo"] = k++;
	num["violet"] = k++;
	for (auto p : num)
		str[p.S] = p.F;
}

void read() {
	cin >> n;
	vector<string> s;
	s.resize(n);
	for (auto &s : s)
		cin >> s;
	for (auto i : s)
		v.push_back(num[i]);
}


set<int> pl[9];
set<int> cool[9];

bool unlocked(int l) {
	if (l == -98 || (0 <= l && l < v.size() && v[l] == 1))
		return true;
	return false;
}

void cool_add(int pos) {
	if (pos < 0) {
		if (viv)
			cout << "\t\tcool_add(" << str[1 - pos] << ' ' << pos << ")" << endl;
		cool[1 - pos].insert(pos);
		return;
	}
	if (viv)
		cout << "\t\tcool_add(" << str[v[pos]] << ' ' << pos << ")" << endl;
	cool[v[pos]].insert(pos);
}

void cool_del(int pos) {
	if (pos < 0) {
		if (viv)
			cout << "\t\tcool_del(" << str[1 - pos] << ' ' << pos << ")" << endl;
		cool[1 - pos].erase(pos);
		return;
	}
	if (viv)
		cout << "\t\tcool_del(" << str[v[pos]] << ' ' << pos << ")" << endl;
	cool[v[pos]].erase(pos);
}

void del_seg(int l, int r) {
	if (viv)
		cout << "\tdel_seg(" << l << ' ' << r << ")" << endl;
	for (int i = 2; i < 9; i++) {
		if (unlocked(l)) {
			auto z = pl[i].lower_bound(r);
			z--;
			int pos = *z;
			if (l < pos) {
				cool_del(pos);
			}
		}
	}
}

void add_seg(int l, int r) {
	if (viv)
		cout << "\tadd_seg(" << l << ' ' << r << ")" << endl;
	for (int i = 2; i < 9; i++) {
		if (unlocked(l)) {
			auto z = pl[i].lower_bound(r);
			z--;
			int pos = *z;
			if (l < pos) {
				cool_add(pos);
			}
		}
	}
}

void get_lr(int pos, int &l, int &r) {
	auto z = pl[0].lower_bound(pos);
	int r0 = *z;
	z--;
	int l0 = *z;
	z = pl[1].lower_bound(pos);
	int r1 = *z;
	z--;
	int l1 = *z;
	r = min(r0, r1);
	l = max(l0, l1);	
}

void add(int pos) {
	int l, r;
	get_lr(pos, l, r);
	if (viv) 
		cout << "add(" << pos << ", lr = " << l << ' ' << r << ")" << endl;
	if (v[pos] >= 2) {
		if (unlocked(l)) {
			auto z = pl[v[pos]].lower_bound(r);
			z--;
			auto old = *z;
			if (l < old && old < pos) {
				cool_del(old);
				cool_add(pos);
			}
			if (old < l) {
				cool_add(pos);
			}
		}
	} else {
		del_seg(l, r);
		add_seg(l, pos);
		add_seg(pos, r);
	}
	pl[v[pos]].insert(pos);
}

void del(int pos) {
	pl[v[pos]].erase(pos);
	int l, r;
	get_lr(pos, l, r);
	if (v[pos] >= 2) {
		if (unlocked(l)) {
			auto z = pl[v[pos]].lower_bound(r);
			z--;
			auto old = *z;
			cool_del(pos);
			if (l < old) {
				cool_add(old);
			}
		}
	} else {
		del_seg(l, pos);
		del_seg(pos, r);
		add_seg(l, r);
	}
}

void build() {
	if (viv)
		cout << "build()" << endl;;
	for (int i = 2; i < 9; i++) {
		pl[i].insert(1 - i);
		cool[i].insert(1 - i);
	}
	pl[0].insert(-99);
	pl[1].insert(-98);
	pl[0].insert(n);
	pl[1].insert(n + 1);

	for (int i = 0; i < n; i++) 
		add(i);
}

void ans() {
	if (viv)
		cout << "\t\t\tans()" << endl;;
	pii bst = {-mod, -mod};
	for (int i = 0; i < 9; i++)
		if (cool[i].size()) {
			int pos = *(cool[i].rbegin());
			bst = max(bst, {pos, i});
			if (viv)
				cout << "\t\tbest of " << str[i] << " on pl = " << pos << endl;
		}
	assert(bst.S != -mod);
	if (viv)
		cout << "ANS = ";
	cout << str[bst.S] << '\n';
	if (viv) {
		cout << "\t! pos = " << bst.F << endl;
		cout << "-- -- IT WAS -- --" << endl;
		for (auto i : v)
			cout << "\t\t" << str[i] << endl;
		cout << "-- -- THE END -- --" << endl;
	}
}

void work() {
	int pl;
	string tp;
	cin >> pl >> tp;
	pl--;

	del(pl);
	v[pl] = num[tp];
	add(pl);

	ans();
}

void solve() {
	prepare();	
	read();
	build();
	ans();
	int q;
	cin >> q;
	while (q--)
		work();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
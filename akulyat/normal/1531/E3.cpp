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
string s;
vector<ll> a, b;
bool viv = false;

int nxt = 0;

int merge(int l, int r, int n, int lvl) {
	if (viv)
		cout << "merge(" << l << ' ' << r << ' ' << n << ' ' << lvl << ")" << endl;
	if (l + 1 >= r)
		return 0;
	int m = (l + r) >> 1;
	if (merge(l, m, n, lvl + 1))
		return 1;
	if (merge(m, r, n, lvl + 1))
		return 1;
	int i = l, j = m, k = l;
	while (i < m && j < r) {
		if (viv) {
			cout << i << " < " << m << ", " << j << " < " << r << endl;
			cout << "\t" << nxt << " == " << s.size() << endl;
		}
		if (nxt == s.size()) {
			if (viv)
				cout << "ALARM for " << n << endl;
			return 1;
		}
		if (s[nxt++] == '0') {
			b[k] = a[i];
			i++;			
		} else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < m) {
		b[k] = a[i];
		i++;
		k++;
	}
	while (j < r) {
		b[k] = a[j];
		j++;
		k++;
	}
	for (int i = l; i < r; i++)
		a[i] = b[i];
	if (viv) {
		for (int i = 0; i < lvl; i++)
			cout << '\t';
		for (auto i : a)
			cout << i << ' ';
		cout << endl;
	}
	if (r - l == n) {
		if (nxt != s.size())
			return -1;
		return 0;
	}
	return 0;
}

int work(int n) {
	a.assign(n, 0);
	b.resize(n);
	for (int i = 0; i < n; i++)
		a[i] = i;
	nxt = 0;
	return merge(0, n, n, 0);
}

void make_inv() {
	for (int i = 0; i < a.size(); i++)
		b[a[i]] = i;
	a = b;	
}

void printer() {
	if (viv)
		cout << "ANS: " << endl;
	make_inv();
	cout << a.size() << '\n';
	for (auto i : a)
		cout << i + 1 << ' ';
	cout << endl;
	exit(0);
}

map<int, int> lm, rm;

int lmoves(int n) {
	if (n <= 1)
		return 0;
	if (lm.count(n))
		return lm[n];
	int a = n / 2, b = n - a;
	return lm[n] = lmoves(a) + lmoves(b) + a;
}

int rmoves(int n) {
	if (n <= 1)
		return 0;
	if (rm.count(n))
		return rm[n];
	int a = n / 2, b = n - a;
	return rm[n] = rmoves(a) + rmoves(b) + a + b - 1;
}

void cut(int &l, int &r) {
	// cout << "cut: " << l << ' ' << r << endl;
	while (l + 1 < r) {
		int m = l + r >> 1;
		int res = work(m);
		if (!res) {
			printer();
		}
		if (res == 1)
			r = m;
		else
			l = m;
		// cout << "get: " << l << ' ' << r << endl;
	}
}

void worker(int l, int r) {
	vector<int> vals;
	int cor = 100;
	for (int i = l - cor; i <= r + cor; i++) 
		if (i > 1)
			vals.push_back(i);
	for (auto val : vals)
		if (!work(val)) 
			printer();	
}

void solve() {
	bool loc = false;
	// loc = true;
	cin >> s;
	if (viv)
		cout << "guy of size: " << s.size() << endl;
	int sz = s.size();
	if (loc)
		sz = rmoves(100000);
	int l = 1, r = 1;	
	while (rmoves(l) < sz)
		l++;
	while (lmoves(r) <= sz)
		r++;
	if (loc) {
		cout << "lr = " << l << ' ' << r << endl;
		return;
	}
	cut(l, r);
	worker(l, r);
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
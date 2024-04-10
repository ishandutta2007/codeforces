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

bool merge(int l, int r, int n, int lvl) {
	if (viv)
		cout << "merge(" << l << ' ' << r << ' ' << n << ' ' << lvl << ")" << endl;
	if (l + 1 >= r)
		return true;
	int m = (l + r) >> 1;
	if (!merge(l, m, n, lvl + 1))
		return false;
	if (!merge(m, r, n, lvl + 1))
		return false;
	int i = l, j = m, k = l;
	while (i < m && j < r) {
		if (viv) {
			cout << i << " < " << m << ", " << j << " < " << r << endl;
			cout << "\t" << nxt << " == " << s.size() << endl;
		}
		if (nxt == s.size()) {
			if (viv)
				cout << "ALARM for " << n << endl;
			return false;
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
	if (r - l == n)
		return (nxt == s.size());
	return true;
}

bool work(int n) {
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
void solve() {
	cin >> s;
	if (viv)
		cout << "guy of size: " << s.size() << endl;
	for (int i = 2; i <= 20; i++) {
		if (work(i)) 
			printer();
	}
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
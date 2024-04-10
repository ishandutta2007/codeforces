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

int n;
vector<int> path;
bool viv = false;

void bad() {
	exit(1);
}

bool direct(int a, int b) {
	cout << "1 " << a << ' ' << b << endl;
	int res;
	cin >> res;
	if (res == -1)
		bad();
	return res;
}

bool seg(int v, int l, int r) {
	vector<int> go;
	for (int i = l; i <= r; i++)
		go.push_back(path[i]);
	if (!go.size())
		return 0;
	cout << "2 " << v << ' ' << go.size() << ' ';
	for (auto i : go)
		cout << i << ' ';
	cout << endl;
	int res;
	cin >> res;
	if (res == -1)
		bad();
	return res;
}



void add(int v, int pref) {
	vector<int> res;
	for (int i = 0; i < pref; i++)
		res.push_back(path[i]);
	res.push_back(v);
	for (int i = pref; i < path.size(); i++)
		res.push_back(path[i]);
	path = res;
}



void add(int v) {
	if (path.empty() || direct(v, path[0])) {
		add(v, 0);
		return;
	}
	if (direct(path.back(), v)) {
		add(v, path.size());
		return;
	}
	int l = 0;
	int r = path.size() - 1;
	while (l + 1 < r) {
		int m = l + r >> 1;
		if (direct(path[m], v))
			l = m;
		else
			r = m;
	}
	add(v, l + 1);
}

void go_left() {
	vector<int> left;
	for (int i = 0; i < n; i++)
		left.push_back(i);
	int r = n - 1;
	bool ans[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = 0;
	int prev = n;
	for (int i = n - 1; i >= 0; i--) {
		while (r >= i)
			r--;
		while (seg(path[i], 0, r))
			r--;
		if (r == i - 1) {
			for (int j = i; j < prev; j++) {
				for (int u = i; u < n; u++) {
					ans[path[j]][path[u]] = true;
				}
			}
			prev = i;
		}
	}
	cout << "3" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << ans[i][j];
		cout << endl;
	}
	int res;
	cin >> res;
	if (res == -1)
		bad();	
}

void solve() {
	cin >> n;
	if (viv) {
		while (n < 4)
			cin >> n;
	}
	path.clear();
	for (int i = 0; i < n; i++)
		add(i);
	if (viv) {
		cout << "path = ";
		for (auto i : path)
			cout << i << ' ';
		cout << '\n';
	}
	go_left();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}
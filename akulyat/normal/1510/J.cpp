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

int n, k;
vector<int> v;
string s, rs;
bool viv = false;

bool emp(string s) {
	for (auto i : s)
		if (i == '#')
			return false;
		return true;		
}

void bad() {
	cout << "-1\n";
}

string get(int n, vector<int> v, int mob) {
	string s(n, '_');
	int now = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i]; j++) {
			if (j >= mob)
				s[now] = '#';
			now++;
		}
		now++;
	}
	if (viv)
		cout << "get: " << s << endl;
	return s;
}

string build(int n, vector<int> v) {
	string t = get(n, v, 0);
	int pl = (int)t.size() - 1;
	int mob = 0;
	while (pl >= 0 && t[pl] == '_')
		pl--, mob++;

	t = get(n, v, mob);

	if (viv)
		cout << "build: " << t << endl;

	return t;
}

bool work(int mob, string s) {
	for (int i = 0; i < n; i++) {
		if (s[i] == '#' && s[i - 1] != '#') {
			for (int j = 1; j <= mob; j++)
				s[i - j] = '#';
		}
	}
	if (viv)
		cout << "see: " << s << endl;

	v.clear();
	int len = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			len++;
		} else {
			v.push_back(len);
			len = 1;
		}
	}
	v.push_back(len - mob);

	if (viv) {
		cout << "blocks: ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}

	vector<int> ans;
	for (int i = 0; i < v.size(); i++) {
		if (i & 1) {
			ans.push_back(v[i]);
			if (viv)
				cout << "add " << ans.back() << " as long" << endl;
		} else {
			v[i]--;
			if (mob == 0) {
				if (v[i])
					return false;
			} else {
				if (v[i] == 1 || (v[i] & 1 && mob == 1)) {
					return false;
				}
				if (v[i] & 1) {
					ans.push_back(2);
					v[i] -= 3;
				}
				while (v[i]) {
					assert(v[i] > 0);
					ans.push_back(1);
					v[i] -= 2;
				}
			}
		}
	}
	if (viv) {
		cout << "\t\tcheck: ";
		for (auto i : ans)
			cout << i << ' ';
		cout << endl;
	}
	assert(build(n - 2, ans) == rs);
	if (viv)
		cout << "\t\t";
	cout << ans.size() << '\n';
	if (viv)
		cout << "\t\t";
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';	
	return true;
}

void solve() {
	if (viv) {
		cout << endl;
		cout << "----------------------" << endl;
		cout << endl;
	}
	cin >> s;
	rs = s;
	s = '_' + s + '_';
	if (emp(s)) {
		cout << "0\n";
		return;
	}
	n = s.size();
	int len = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '#') {
			if (len)
				v.push_back(len);
			len = 0;
		} else len++;
	}
	v.push_back(len);
	if (viv) {
		cout << "v: ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	int mob = mod;
	for (auto i : v)
		mob = min(mob, i - 1);
	if (viv)
		cout << "mob = " << mob << endl;

	for (int i = 0; i <= mob; i++) {
		// if (abs(i) <= 10 || abs(mob - i) <= 10)
		if (abs(mob - i) <= 2)
			if (work(i, s))
				return;
	}
	// for (int i = 0; i < n; i++) {
	// 		if (work(i, s))
	// 			return;
	// }
	return void(bad());
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// if (viv)
	// 	cin >> t;
	while (t--)
		solve();

	return 0;
}
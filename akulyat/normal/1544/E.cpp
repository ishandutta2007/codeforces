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
vector<int> c;
bool viv = false;

vector<int> cnt(string s) {
	if (viv)
		cout << "cnt()" << endl;
	vector<int> res(26, 0);
	for (auto i : s)
		res[i - 'a']++;
	return res;
}

void solver_1(int b) {
	if (viv)
		cout << "solver_1()" << endl;
	string res;
	res += char('a' + b);
	c[b]--;
	for (int i = 0; i < 26; i++) {
		while (c[i]--)
			res += char('a' + i);
	}
	cout << res << '\n';
}

void solver_all(int b) {
	if (viv)
		cout << "solver_all()" << endl;
	string res;
	for (int i = 0; i < 26; i++) {
		while (c[i]--)
			res += char('a' + i);
	}
	cout << res << '\n';
}

void up(int &b) {
	while (b < 26 && !c[b]) 
		b++;
}

void solver_aa(int b) {
	if (viv)
		cout << "solver_aa()" << endl;
	string res;
	res += char('a' + b);
	c[b]--;

	int mode = 0;
	int sc = b + 1;
	while (c[b]) {
		if (!mode) {
			res += char('a' + b);
			c[b]--;
		} else {
			up(sc);
			if (sc == 26) {
				cout << "SHIT!!!" << endl;
				exit(1);
			}
			res += char('a' + sc);
			c[sc]--;			
		}
		mode ^= 1;
	}

	for (int i = 0; i < 26; i++) {
		while (c[i]--)
			res += char('a' + i);
	}
	cout << res << '\n';
}

void solver_3(int fr, int sc, int tr) {
	if (viv)
		cout << "solver_3()" << endl;
	string res;

	res += char('a' + fr);
	c[fr]--;
	res += char('a' + sc);
	c[sc]--;

	while (c[fr]) {
		res += char('a' + fr);
		c[fr]--;		
	}
	res += char('a' + tr);
	c[tr]--;

	for (int i = 0; i < 26; i++) {
		while (c[i]--)
			res += char('a' + i);
	}
	cout << res << '\n';
}

void solver_2(int fr, int sc) {
	if (viv)
		cout << "solver_2()" << endl;
	string res;

	res += char('a' + fr);
	c[fr]--;
	while (c[sc]) {
		res += char('a' + sc);
		c[sc]--;		
	}

	for (int i = 0; i < 26; i++) {
		while (c[i]--)
			res += char('a' + i);
	}
	cout << res << '\n';
}

void solve() {
	cin >> s;
	if (viv)
		cout << "\tsolve(" << s << ")" << endl;
	n = s.size();
	c = cnt(s);

	for (int i = 0; i < 26; i++) {
		if (c[i] == 1) {
			solver_1(i);
			return;
		}
	}

	int fr = 0;
	up(fr);
	int sc = fr + 1;
	up(sc);

	if (sc == 26) {
		solver_all(fr);
		return;
	}

	int c1 = c[fr];
	int call = n;
	c1 -= 2;
	call -= 2;
	if (c1 * 2 <= call) {
		solver_aa(fr);
		return;
	}

	int tr = sc + 1;
	up(tr);

	if (tr < 26) {
		solver_3(fr, sc, tr);
		return;
	}

	solver_2(fr, sc);
	return;
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
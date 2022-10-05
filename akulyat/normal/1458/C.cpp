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

// ifstream in;
// ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<vector<int>> v;
bool viv = false;

vector<int> in(const vector<int> &p) {
	vector<int> res(p.size());
	for (int i = 0; i < n; i++)
		res[p[i]] = i;
	return res;
}

struct table {
	vector<vector<int>> val;
	int n;
	int r = 0, c = 0, sh = 0;

	void read(int _n) {
		n = _n;
		val.resize(n, vector<int>(n));
		for (auto &l : val)
			for (auto &i : l)
				cin >> i, i--;
	}

	void print() {
		// cout << r << ' ' << c << ' ' << sh << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a = (r + i) % n;
				int b = (c + j) % n;
				int v = (val[a][b] + sh) % n;
				cout << 1 + v << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		if (viv)
			cout << endl;
	}

	table b() const {
		table cp = *this;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++) {
				swap(cp.val[i][j], cp.val[j][i]);
			}
		swap(cp.r, cp.c);
		return cp;
	}

	table i() const {
		table cp = *this;
		for (int i = 0; i < n; i++)
			cp.val[i] = in(cp.val[i]);
		return cp;
	}

	void adder(int v1, int v2, int v3) {
		r = (r + (n + v1)) % n;
		c = (c + (n + v2)) % n;
		sh = (sh + (n + v3)) % n;
	}

	void R() { adder(0, -1, 0); }
	void L() { adder(0, 1, 0); }
	void D() { adder(-1, 0, 0); }
	void U() { adder(1, 0, 0); }
	void add() { adder(0, 0, 1); }
	void dec() { adder(0, 0, -1); }

};

void rep(string &s) {
	string res;
	for (auto i : s) {
		if (i != 'C')
			res += i;
		else
			res += "IBI";
	}
	s = res;
	return;
	res.clear();
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (i + 1 == n || s[i] != s[i + 1])
			res += s[i];
		else
			i++;
	}
	s = res;
}

void solve() {
	cin >> n >> m;
	table v, vb, vcb, vc, vib, vi;
	v.read(n);
	table V = v;

	vb = v.b();
	vcb = vb.i();
	vc = vcb.b();
	vib = vc.i();
	vi = vib.b();	
		if (viv) {
			cout << "V: \n";
				V.print();
			cout << "v: \n";
				v.print();
			cout << "vb: \n";
				vb.print();
			cout << "vcb: \n";
				vcb.print();
			cout << "vc: \n";
				vc.print();
			cout << "vib: \n";
				vib.print();
			cout << "vi: \n";
				vi.print();
			cout << "____ " << endl;
		}

	string s;
	cin >> s;
	rep(s);
	if (viv)
		cout << "s = " << s << '\n';
	for (auto i : s) {
		if (i == 'R') {
			if (viv)
				V.R();

			v.R();
			vb.D();
			vcb.D();
			vc.R();
			vib.add();
			vi.add();
		}
		if (i == 'L') {
			if (viv)
				V.L();

			v.L();
			vb.U();
			vcb.U();
			vc.L();
			vib.dec();
			vi.dec();
		}
		if (i == 'D') {
			if (viv)
				V.D();

			v.D();
			vb.R();
			vcb.add();
			vc.add();
			vib.R();
			vi.D();
		}
		if (i == 'U') {
			if (viv)
				V.U();

			v.U();
			vb.L();
			vcb.dec();
			vc.dec();
			vib.L();
			vi.U();
		}
		if (i == 'I') {
			if (viv)
				V = V.i();
			swap(v, vi);
			swap(v, vib);
			swap(v, vc);
			swap(v, vcb);
			swap(v, vb);

			swap(v, vib);
			swap(vb, vc);
		}
		if (i == 'B') {
			if (viv)
				V = V.b();
			swap(v, vb);
			swap(v, vcb);
			swap(v, vc);
			swap(v, vib);
			swap(v, vi);

			swap(v, vcb);
			swap(vi, vc);
		}
		if (viv) {
			cout << "V: \n";
				V.print();
			cout << "v: \n";
				v.print();
			cout << "vb: \n";
				vb.print();
			cout << "vcb: \n";
				vcb.print();
			cout << "vc: \n";
				vc.print();
			cout << "vib: \n";
				vib.print();
			cout << "vi: \n";
				vi.print();
			cout << "____ " << endl;
		}
	}
	if (viv)
		cout << "AAAAAAAAA\n";
	v.print();
	if (viv)
		V.print();
	if (viv)
		cout << "AAAAAAAAA\n";
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
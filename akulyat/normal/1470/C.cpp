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

int n, k, pl, st, cnt = 0;
vector<int> v, pre;
vector<vector<int>> q;
bool viv = false;

int sh = 239;

vector<int> get(int n, int k) {
	vector<int> res(n, k);
	return res;
}

void step() {
	vector<int> fv(n, 0);
	for (int i = 0; i < n; i++) {
		int l = (i + n - 1) % n;
		int r = (i + n + 1) % n;
		int tol = v[i] / 2;
		if (!i)
			tol = 0;
		fv[l] += tol;
		fv[r] += v[i] - tol;
	}
	pre = v;
	v = fv;
	if (viv) {
		cout << "new v = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
}

int ask(int pl) {
	pl %= n;
	pl += n;
	pl %= n;
	cout << "? " << pl + 1 << endl;
	int ans;
	if (!viv)
		cin >> ans;
	else {
		int rpl = pl - sh + n;
		rpl %= n;
		ans = v[rpl];
	}

	assert(cnt < 1000);
	q.push_back({cnt, pl, ans - k});
	if (viv)
		cout << "add " << q[q.size() - 1][0] << ' ' << q[q.size() - 1][1] << ' ' << q[q.size() - 1][2] << endl;
	cnt++;
	return ans;
}

bool good() {
	int a = q[q.size() - 2][2];
	int b =  q[q.size() - 1][2];
	if (a < 0 || b < 0)
		return false;
	if (b == 0)
		return false;
	return true;
}

void ans(int val) {
	val %= n;
	val += n;
	val %= n;
	cout << "! " << val + 1 << endl;
	exit(0);
}

void get_ans(int pl) {
	if (viv)
		cout << "get_ans(" << pl << ")\n";
	int r = pl;
	int sh = 1;
	int l = r - sh;
	while (q[q.size() - 1][2] > 0) {
		sh *= 2;
		l = r - sh;
		ask(l);
		step();
	}
	while (l + 1 != r) {
		int m = l + r >> 1;
		ask(m);
		step();
		if (q[q.size() - 1][2] <= 0)
			l = m;
		else
			r = m;
	}
	ans(l);
}

void work() {
	int add = 1;

	ask(pl);	
	step();
	ask(pl + add);
	if (good()) {
		step();
		get_ans(pl + add);
	}
	if (viv) {
		cout << "pre = ";
		for (auto i : pre)
			cout << i << ' ';
		cout << endl;
		cout << "v = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
		cout << endl;
	}
	step();
	if (cnt % 5)
		pl++;
	pl += st;
}


void solve() {
	cin >> n >> k;
	pre = v = get(n, k);

	st = int(sqrt(n));
	pl = 0;
	while (true)
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
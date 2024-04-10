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
vector<int> p, ps;
map<int, int> last;
bool viv = false;



vector<int> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<int> res;
	for (int i = 2; i <= last; i++) {
		if (prime[i])
			res.push_back(i);
		if ((ll)i * i <= last)
			for (int j = i * i; j <= last; j += i)
				prime[j] = false;
	}
	return res;
}

int A(int a) {
	cout << "A " << a << endl;
	int res;
	cin >> res;
	last[a] = res;
	return res;
}

int B(int a) {
	if (a > n)
		return 0;
	cout << "B " << a << endl;
	int res;
	cin >> res;
	last[a] = res;
	return res;
}

void C(int a) {
	cout << "C " << a << endl;
	exit(0);
}

int get_small() {
	for (auto d : ps) {
		B(d);
	}
	int res = 1;
	for (auto d : ps) {
		int now = 1;
		int cnt = 1;
		while (cnt) {
			now *= d;
			cnt = B(now);
		}
		now /= d;
		res *= now;
	}
	return res;
}

int get_big(vector<int> p);


int work(vector<int> pa, vector<int> pb) {
	int a1 = A(1);
	for (auto d : pa) {
		int cnt = B(d);
		if (cnt == 2)
			return d;
	}
	int a2 = A(1);
	if (a2 + pa.size() == a1)
		return get_big(pb);
	for (auto d : pa) {
		int cnt = B(d);
		if (cnt == 1)
			return d;
	}
	assert(false);
}

int get_big(vector<int> p) {
	if (viv) {
		cout << "get_big(";
		for (auto i : p)
			cout << i << ' ';
		cout << ")" << endl;
	}
	if (p.empty())
		return 1;
	vector<int> pa, pb;
	for (int i = 0; i < p.size(); i++)
		if (i <= p.size() / 2)
			pa.push_back(p[i]);
		else
			pb.push_back(p[i]);
	return work(pa, pb);
}

void solve() {
	cin >> n;
	p = erat(n);
	int ns = sqrt(n) + 1;
	ns = min(ns, n);
	ps = erat(ns);
	if (viv) {
		cout << "p = ";
		for (auto i : p)
			cout << i << ' ';
		cout << endl;
		cout << "ps = ";
		for (auto i : ps)
			cout << i << ' ';
		cout << endl;
	}

	vector<int> fp;
	int mx = 0;
	if (ps.size())
		mx = ps.back();
	for (auto i : p)
		if (i > mx)
			fp.push_back(i);
	p = fp;
	if (viv) {
		cout << "p = ";
		for (auto i : p)
			cout << i << ' ';
		cout << endl;
	}


	int ans1 = get_small();
	int ans2 = get_big(p);
	if (viv) {
		cout << "ans1, ans2 = " << ans1 << ' ' << ans2 << endl;
	}
	C(ans1 * ans2);
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
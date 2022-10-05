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

ll n;
vector<ll> v;
bool viv = false;

bool w(vector<ll> &v) {
	vector<ll> v2 = v;
	ll n = v.size();
	for (int i = 0; i < n; i++) {
		if (v[i] > 1 && (i == 0 || v[i - 1] <= 1)) {
			if (i > 0)
				v2[i - 1]++;
			v2[i]--;
		}
		if (v[i] > 1 && (i == n - 1 || v[i + 1] <= 1)) {
			if (i < n - 1)
				v2[i + 1]++;
			v2[i]--;
		}
	}
	bool cont = (v != v2);
	v = v2;
	return cont;
}

void work(vector<ll> v) {
	for (auto i : v)
		cout << i << ' ';
	cout << endl;
	bool cont = true;
	while (cont) 
		cont = w(v);
	cout << "res: ";
	for (auto i : v)
		cout << i << ' ';
	cout << endl;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ll sum = 0;
	for (auto i : v)
		sum += i;

	ll val = (n * (n - 1)) / 2;
	ll cnt = 0;
	// cout << sum << ' ' << val << endl;
	while ((sum - val) % (n))
		val--, cnt++;

	ll start = (sum - val) / n;

	vector<ll> delt(n, 1);
	delt[n - 1 - cnt] = 0;
	if (viv) {
		for (auto i : delt)
			cout << i << ' ';
		cout << endl;
		vector<ll> d;
		for (int i = 1; i < n; i++)
			d.push_back(v[i] - v[i - 1]);
		work(d);
	}

	vector<ll> res;
	ll now = start;
	res.push_back(now);
	for (int i = 0; i < n - 1; i++) {
		now += delt[i];
		res.push_back(now);
	}

	for (auto i : res)
		cout << i << ' ';
	cout << '\n';

	return;
	for (int i = 0; i < 100; i++) {
		vector<ll> v;
		for (int j = 0; j < 13; j++)
			v.push_back(rand() % 20 + 1);
		work(v);
	}
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
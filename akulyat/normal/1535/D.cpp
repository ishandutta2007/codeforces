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

ll n, k;
vector<ll> v, cnt;
bool viv = false;
string s;

void get(int i) {
	assert(i < n);
	assert(i >= 0);
	if (v[i] == -1) {
		cnt[i] = 0;
		cnt[i] += cnt[2 * i + 1];
		cnt[i] += cnt[2 * i + 2];
	}
	if (v[i] == 1)
		cnt[i] = cnt[2 * i + 1];
	if (v[i] == 0)
		cnt[i] = cnt[2 * i + 2];
}

void put(int i) {
	if (s[i] == '?')
		v[i] = -1;
	else
		v[i] = s[i] - '0';
}

void prepare() {
	cnt.resize(2 * n + 1, 1);
	for (int i = n - 1; i >= 0; i--) {
		get(i);
	}
}

void work() {
	int pl;
	string str;
	cin >> pl >> str;
	pl--;
	pl = n - 1 - pl;
	s[pl] = str[0];
	put(pl);
	while (pl != 0) {
		// cout << "GET " << pl << endl;
		get(pl);
		pl = (pl - 1) >> 1;
		// cout << pl << endl;
	}
	get(0);

	cout << cnt[0] << '\n';
	if (viv) {
		cout << "\t";
		for (auto i : cnt)
			cout << i << ' ';
		cout << endl;
		cout << "\t" << s << endl;
	}
}

void solve() {
	cin >> k;
	n = (1 << k) - 1;
	cin >> s;
	reverse(s.begin(), s.end());
	v.resize(n);
	for (int i = 0; i < n; i++)
		put(i);
	prepare();

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
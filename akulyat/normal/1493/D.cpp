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

ll n, q;
vector<ll> v;
vector<pii> qr;
vector<int> ans;
bool viv = false;


vector<int> cnt;
vector<unordered_map<int, int>> lcnt;
ll cans = 1;

void prepare() {
	cnt.resize(ml, 0);
	lcnt.resize(n);
}

void work(pii p) {
	int pl = p.F;
	int val = p.S;
	vector<int> pr;
	auto fval = val;
	for (int i = 2; i < sqrt(val) + 2; i++) {
		while (!(fval % i)) {
			pr.push_back(i);
			fval /= i;
		}
	}
	if (fval - 1)
		pr.push_back(fval);

	for (auto d : pr) {
		if (lcnt[pl][d] == 0)
			cnt[d]++;
		lcnt[pl][d]++;
		if (cnt[d] == n) {
			cans *= d;
			cans %= mod;
			for (int i = 0; i < n; i++) {
				if (lcnt[i][d] == 1)
					cnt[d]--;
				lcnt[i][d]--;
			}
		}
	}

	cans %= mod;
	ans.push_back(cans);
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		qr.push_back({i, val});
	}
	for (int i = 0; i < q; i++) {
		int val, pl;
		cin >> pl >> val;
		pl--;
		qr.push_back({pl, val});
	}
	prepare();
	for (auto p : qr)
		work(p);
	reverse(ans.begin(), ans.end());
	while (ans.size() > q)
		ans.pop_back();
	reverse(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << '\n';	
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
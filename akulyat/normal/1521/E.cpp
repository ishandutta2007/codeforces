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

int sum, n, k, same;
vector<pii> v;
vector<vector<int>> ans;
bool viv = false;

int can_same(int n) {
	return n * ((n + 1) / 2);
}
int can_sum(int n) {
	int qn = n;
	if (qn & 1)
		qn--;
	return n * n - qn * qn / 4; 
}

bool build(int n) {
	ans.clear();
	ans.resize(n, vector<int>(n, -1));

	auto pr = v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (pr.size() && !pr.back().F)
				pr.pop_back();
			if ((i & 1) && !(j & 1) && pr.size()) {
				ans[i][j] = pr.back().S;
				pr.back().F--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (pr.size() && !pr.back().F)
				pr.pop_back();
			if (!(i & 1) && !(j & 1) && pr.size()) {
				ans[i][j] = pr.back().S;
				pr.back().F--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (pr.size() && !pr.back().F)
				pr.pop_back();
			if (!(i & 1) && (j & 1) && pr.size()) {
				ans[i][j] = pr.back().S;
				pr.back().F--;
			}
		}
	}
	while (pr.size() && !pr.back().F)
		pr.pop_back();
	if (pr.size()) {
		// cout << "Can't build " << n << endl;
		// for (auto &l : ans) {
		// 	for (auto i : l)
		// 		cout << i << ' ';
		// 	cout << '\n';
		// }
		// cout << "pr: ";
		// for (auto p : pr)
		// 	cout << p.F << ' ' << p.S << "; ";
		// cout << endl;
		// exit(1);
		return false;
	}

	for (auto &l: ans)
		for (auto &i : l)
			i++;
	cout << n << '\n';
	for (auto &l : ans) {
		for (auto i : l)
			cout << i << ' ';
		cout << '\n';
	}
	return true;
}


void solve() {
	cin >> sum >> k;
	v.resize(k);
	for (auto &i : v)
		cin >> i.F;
	for (int i = 0; i < k; i++)
		v[i].S = i;
	sort(v.begin(), v.end());

	same = 0;
	for (auto i : v)
		same = max(same, i.F);

	n = 0;
	while (can_same(n) < same || can_sum(n) < sum)
		n++;
	while (!build(n))
		n++;
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

/*
111111
202020
111111
202020
111111
202020

1212
2020
1212
2020



596B
1030
7A8C
2040

1212
3030
1212
3030

-32-
3232
-32-

-26-
3704
-15-

-60-
7183
294A
-5B-

-0-0-
0.0.0
-0-0-
0.0.0
-0-0-


-0-0-0
0.0.0.
-0-0-0
0.0.0.
-0-0-0
0.0.0.

121
303
121



*/
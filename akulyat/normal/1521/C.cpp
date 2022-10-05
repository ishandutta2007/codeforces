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
bool viv = false;

int ask(int t, int i, int j, int x) {
	cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
	int res;
	cin >> res;
	if (res == -1) {
		exit(0);
	}
	return res;
}

void solve() {
	cin >> n;
	if (viv)
		cout << "work " << n << endl;
	vector<int> ans;
	vector<vector<int>> pl(n + 1);
	for (int i = 0; i < n - 1; i++) {
		ans.push_back(ask(2, i, i + 1, 1));
		pl[ans.back()].push_back(i);
	}
	vector<int> res(n, -1);
	for (int i = 3; i <= n; i++) {
		if (pl[i].size() == 2) {
			res[pl[i].back()] = i;
		}
		if (pl[i].size() == 1) {
			int pl1 = pl[i][0];
			int pl2 = pl[i][0] + 1;
			int pl0 = pl1 - 1;
			int pl3 = pl2 + 1;
			if (pl3 < n && ans[pl2] > i)
				res[pl1] = i;
			if (pl0 >= 0 && ans[pl0] > i)
				res[pl2] = i;
		}
	}
	bool need = true;
	for (int i = 0; i < n - 1; i++)
		if (ans[i] == 1)
			res[i] = 1, need = false;
	if (need)
		res[n - 1] = 1;	
	int one = -1;
	for (int i = 0; i < n; i++)
		if (res[i] == 1)
			one = i;
	if (viv) {
		cout << "see: ";
		for (auto i : res)
			cout << i << ' ';
		cout << '\n';
	}
	for (int i = 0; i < n; i++)
		if (res[i] == -1) {
			if (i + 1 < n && res[i + 1] == -1 && ans[i] > 2) {
				int mn = ans[i];
				int pl = i + uniform_int_distribution<int>(0, 1)(rng);
				int val = ask(1, one, pl, n - 1);
				res[pl] = val;

				int fr = i + (i + 1) - pl;
				if (val != mn)
					res[fr] = mn;
				else
					res[fr] = ask(1, one, fr, n - 1);
			} else {
				res[i] = ask(1, one, i, n - 1);
			}
		}
	cout << "! ";
	for (auto i : res)
		cout << i << ' ';
	cout << endl;
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
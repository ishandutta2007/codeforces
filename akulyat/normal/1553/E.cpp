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

int n, m;
vector<int> v, ans;
bool viv = false;


bool can(int val) {
	vector<int> id(n);
	for (int i = 0; i < n; i++)
		id[i] = (i + n - val) % n;
	vector<int> will(n);
	for (int i = 0; i < n; i++)
		will[id[i]] = i;


	vector<int> vec = v;
	for (auto &i : vec)
		i = will[i];

	vector<bool> col(n, false);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (col[i] == false) {
			col[i] = true;
			int pl = vec[i];
			while (col[pl] == false) {
				col[pl] = true;
				ans++;
				pl = vec[pl];
			}
		}
	}
	return (ans <= m);
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	ans.clear();

	vector<int> cnt(n, 0);
	for (int i = 0; i < n; i++) {
		int dif = i - v[i];
		dif %= n;
		dif += n;
		dif %= n;
		cnt[dif]++;
	}

	vector<int> ch;
	for (int i = 0; i < n; i++) 
		if ((cnt[i] + 2) * 4 >= n)
			ch.push_back(i);

	for (auto val : ch)
		if (can(val))
			ans.push_back(val);

	cout << ans.size() << "   ";
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
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
#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<pll, pll>   ppll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll h, v;
vector<ll> hor, ver;
vector<pll> ans;
vector<vector<pll>> vec;
pll now;

bool viv = false;

void show(pll now) {
	ans.push_back(now);
}

void step(vector<vector<ll>> &hor, vector<vector<ll>> &ver, int h, int v) {
	vec.push_back({});
	while (hor[h].size() && ver[v].size()) {
		ll x = hor[h].back();
		ll y = ver[v].back();
		hor[h].pop_back();
		ver[v].pop_back();
		vec.back().push_back({x, y});
	}
}

vector<vector<ll>> beat(vector<ll> vec, bool &good) {
	int sum = 0;
	for (auto i : vec)
		sum += i;
	if (sum & 1) {
		good = false;
		return {};
	}

	vector<vector<bool>> dp(vec.size() + 1, vector<bool>(sum / 2 + 1, false));
	dp[0][0] = true;
	bool lgood = false;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j <= min(vec[i] - 1, (ll)sum / 2); j++)
			dp[i + 1][j] = dp[i][j];
		for (int j = vec[i]; j <= sum/2; j++)
			dp[i + 1][j] = dp[i][j] | dp[i][j - vec[i]];
		if (dp[i + 1].back())
			lgood = true;
	}
	if (!lgood) {
		good = false;
		return {};
	}
	vector<vector<ll>> res(2);
	int need = sum / 2;
	for (int i = vec.size(); i > 0; i--) {
		int pl = 0;
		if (dp[i][need] && !dp[i - 1][need]) {
			need -= vec[i - 1];
			pl = 1;
		}
		res[pl].push_back(vec[i - 1]);
	}
	return res;
}


void solve() {
	cin >> h;
	hor.resize(h);
	for (auto &i : hor)
		cin >> i;

	cin >> v;
	ver.resize(v);
	for (auto &i : ver)
		cin >> i;

	sort(hor.begin(), hor.end());
	sort(ver.begin(), ver.end());

	vec.clear();
	ans.clear();

	bool good = true;
	auto seg_h = beat(hor, good);
	auto seg_v = beat(ver, good);

	if (!good || hor.size() != ver.size()) {
		cout << "NO\n";
		return;
	}


	if (seg_h[0].size() > seg_h[1].size())
		swap(seg_h[0], seg_h[1]);
	if (seg_v[0].size() < seg_v[1].size())
		swap(seg_v[0], seg_v[1]);

	step(seg_h, seg_v, 0, 0);
	step(seg_h, seg_v, 0, 1);
	step(seg_h, seg_v, 1, 0);
	step(seg_h, seg_v, 1, 1);


	sort(vec[0].begin(), vec[0].end(), [&](const pll &a, const pll &b) {
			return a.S * b.F < b.S * a.F;
		}
	);
	sort(vec[3].begin(), vec[3].end(), [&](const pll &a, const pll &b) {
			return a.S * b.F < b.S * a.F;
		}
	);

	now = {0, 0};
	for (int i = 0; i < 4; i++) {
		// cout << i << ": \n";
		for (auto p : vec[i]) {
			// cout << "\t" << p.F << ' ' << p.S << endl;
			ll x = p.F;
			ll y = p.S;
			if ((i >> 1) & 1)
				x = -x;
			if ((i >> 0) & 1)
				y = -y;

			now.F += x;
			show(now);
			now.S += y;
			show(now);
		}
	}

	cout << "YES\n";
	for (auto p : ans) {
		cout << p.F << ' ' << p.S << '\n';
	}
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
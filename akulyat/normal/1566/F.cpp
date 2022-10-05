#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;



#define int long long

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
// typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<int> p;
set<int> ps;
vector<pii> seg;
bool viv = false;

void read() {
	cin >> n >> m;
	p.resize(n);
	for (auto &val : p)
		cin >> val;
	ps.clear();
	for (auto i : p)
		ps.insert(i);
	seg.resize(m);
	for (auto &s : seg)
		cin >> s.F >> s.S;

}

void clear1() {
	vector<pii> rseg;
	for (auto s : seg) {
		int l = s.F;
		int r = s.S;
		auto z = ps.lower_bound(l);
		if (z != ps.end() && (*z) <= r) {

		} else {
			rseg.push_back(s);			
		}
	}
	seg = rseg;
}

void clear2() {
	vector<pii> rseg;
	sort(seg.begin(), seg.end());
	for (auto s : seg) {
		while (rseg.size() && s.S <= rseg.back().S)
			rseg.pop_back();
		rseg.push_back(s);
	}	
	seg = rseg;
}

void make(vector<map<pii, ll>> &dp, int i, pii pr, ll val) {
	if (dp[i].find(pr) == dp[i].end())	
		dp[i][pr] = val;
	else
		dp[i][pr] = min(dp[i][pr], val);
}

void solver() {
	n = ps.size();
	m = seg.size();
	vector<map<pii, ll>> dp(m);
	for (int i = 0; i < m; i++) {
		if (viv)
			cout << "seg " << i << endl;
		ll l = seg[i].F;
		ll r = seg[i].S;
		{ // use next point
			auto z = ps.upper_bound(r);
			if (z != ps.end()) { // next point exist				
				int nx = *z;
				if (viv)
					cout << "\tnx = " << nx << endl;
				if (i == 0) { // first seg case
					pii pr = {nx, 0};
					make(dp, i, pr, 2 * (nx - r));
					pr = {nx, 1};
					make(dp, i, pr, 1 * (nx - r));
				} else { // not first
					for (auto pp : dp[i - 1]) { // same point used by prev seg
						auto old_pr = pp.F;
						if (old_pr.F == nx) 
							make(dp, i, old_pr, dp[i - 1][old_pr]);
					}
					for (auto pp : dp[i - 1]) { // point used only for my seg
						auto old_pr = pp.F;
						if (old_pr.F != nx) {
							pii pr = {nx, 0};
							make(dp, i, pr, pp.S + 2 * (nx - r));
							pr = {nx, 1};
							make(dp, i, pr, pp.S + 1 * (nx - r));
						}
					}
				}
			} else { // no next point

			}
		}
		{ // use prev point
			auto z = ps.lower_bound(l);
			if (z != ps.begin()) { // prev point exist
				z--;				
				int prv = *z;
				if (viv)
					cout << "\tprv = " << prv << endl;
				if (i == 0) { // first seg case
					pii pr = {prv, 0};
					make(dp, i, pr, 1 * (l - prv));
					pr = {prv, 1};
					make(dp, i, pr, 2 * (l - prv));
				} else { // prev seg exist
					if (prv < seg[i - 1].F) { // prev is prev for previous seg
						pii pr = {prv, 0};
						if (dp[i - 1].find(pr) != dp[i - 1].end())
							make(dp, i, pr, dp[i - 1][pr] + 1 * (l - seg[i - 1].F));
						pr = {prv, 1};
						if (dp[i - 1].find(pr) != dp[i - 1].end())
							make(dp, i, pr, dp[i - 1][pr] + 2 * (l - seg[i - 1].F));
					} else { // prev was nxt for previous seg
						for (auto pp : dp[i - 1]) {
							auto old_pr = pp.F;
							if (old_pr.F == prv) {
								pii pr = {prv, 0};
								make(dp, i, pr, dp[i - 1][pr] + 1 * (l - prv));
								pr = {prv, 1};
								make(dp, i, pr, dp[i - 1][pr] + 2 * (l - prv));
							}
						}
						for (auto pp : dp[i - 1]) {
							auto old_pr = pp.F;
							if (old_pr.F != prv) {
								pii pr = {prv, 0};
								// make(dp, i, pr, dp[i - 1][pr] + 1 * (l - prv));
								make(dp, i, pr, pp.S + 1 * (l - prv));
								pr = {prv, 1};
								// make(dp, i, pr, dp[i - 1][pr] + 2 * (l - prv));
								make(dp, i, pr, pp.S + 2 * (l - prv));
							}
						}
					}
				}
			} else {
				// smth
			}
		}
	}

	if (viv) {
		for (int i = 0; i < m; i++) {
			cout << "ans for seg " << i << endl;
			for (auto pp : dp[i]) {
				cout << "\t{" << pp.F.F << ' ' << pp.F.S << "} = " << pp.S << endl;
			}
		}
	}

	ll ans = 0;
	if (m) {
		ans = inf;
		for (auto p : dp.back())
			ans = min(ans, p.S);
	}
	cout << ans << '\n';
}

void solve() {
	read();
	clear1();
	clear2();
	if (viv) {
		cout << "seg = " << endl;
		for (auto s : seg)
			cout << s.F << ' ' << s.S << endl;
		cout << endl;
	}
	solver();
}

signed main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}
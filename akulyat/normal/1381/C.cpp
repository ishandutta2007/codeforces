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

ll n, x, y;
vector<ll> b;
bool viv = false;

void bad() {
	cout << "NO\n";
	if (viv)
		cout << "\n\n\n\n\n";
}

ll get_ban() {
	set<ll> have;
	for (int i = 0; i <= n; i++)
		have.insert(i);
	for (auto i : b)
		have.erase(i);
	return *have.begin();	
}

void show(vector<ll> cnt, ll need) {
	if (viv) {
		cout << "\t\t";
		for (auto i : cnt)
			cout << i << ' ';
		cout << endl;
	}
	ll ban = get_ban();

	vector<ll> ans(n, -1);
	vector<pll> pr;

	ll x_left = x;
	for (int i = 0; i < n; i++) {
		if (cnt[b[i]]) {
			pr.push_back({b[i], i});
			cnt[b[i]]--;
		} else {
			if (x_left)
				ans[i] = b[i], x_left--;
			else {
				if (need)
					pr.push_back({ban, i}), need--;
				else
					ans[i] = ban;
			}
		}
	}
	
	sort(pr.begin(), pr.end());
	ll pr_sz = pr.size();
	for (int i = 0; i < pr_sz; i++)
		pr.push_back(pr[i]);
	for (int i = 0; i < pr_sz; i++) {
		ans[pr[i].S] = pr[i + pr_sz / 2].F;
	}

	cout << "YES\n";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
}

void check(vector<ll> ans) {
	if (viv) {
		ll mx = 0;
		for (int i = 0; i < n; i++)		
			mx += b[i] == ans[i];

		ll my = 0;
		multiset<ll> sb, sans;
		for (auto i : b)
			sb.insert(i);
		for (auto i : ans)
			sans.insert(i);
		for (int i = 0; i <= n; i++)
			my += min(sb.count(i), sans.count(i));
		cout << "would have " << x << " " << y << '\n';
		cout << "but   have " << mx << ' ' << my << endl;;
		cout << endl;
		assert(mx == x);
		assert(my == y);
	}	
}

void solve() {
	cin >> n >> x >> y;
	b.clear();
	b.resize(n);
	for (auto &i : b)
		cin >> i, i--;

	vector<ll> cnt(n + 1);
	for (auto i : b)
		cnt[i]++;

	vector<vector<int>> pl(n + 1);
	for (int i = 0; i < n; i++)
		pl[b[i]].push_back(i);
	set<pll> ss;
	for (int i = 0; i <= n; i++)
		ss.insert({-(ll)pl[i].size(), i});

	vector<ll> ans(n, -1);	
	for (int i = 0; i < x; i++) {
		auto p = *ss.begin();
		// cout << "See " << -p.F << ' ' << p.S << endl;

		ss.erase(p);
		ss.insert({p.F + 1, p.S});

		ll val = p.S;
		ll use_pl = pl[val].back();
		pl[val].pop_back();

		ans[use_pl] = val;
	}

	vector<pll> pl1, pl2;

	for (int i = 0; i < n; i++)
		if (ans[i] == -1)
			pl1.push_back({b[i], i});
	sort(pl1.begin(), pl1.end());
	for (int i = 0; i < pl1.size(); i++) {
		pl2.push_back(pl1[(i + pl1.size() / 2) % pl1.size()]);		
	}

	auto ban = get_ban();
	ll left = n - y;
	for (int i = 0; i < pl1.size(); i++)
		ans[pl1[i].S] = pl2[i].F;

	for (int i = 0; i < pl1.size(); i++)
		if (b[pl1[i].S] == ans[pl1[i].S])
			ans[pl1[i].S] = ban, left--;

	if (left < 0)
		return void(bad());

	for (int i = 0; i < pl1.size(); i++)
		if (ans[pl1[i].S] != ban && left)
			ans[pl1[i].S] = ban, left--;

	cout << "YES\n";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
	check(ans);
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}
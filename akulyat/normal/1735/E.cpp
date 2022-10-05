#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }
 
 
bool viv = false;
int n;
vector<int> d1, d2;
 
bool work(int points_diff) {
	int p1 = 0;
	int p2 = points_diff;
 
	multiset<int, greater<int>> s1, s2;
	for (auto i : d1)
		s1.insert(i);
	for (auto i : d2)
		s2.insert(i);
 
 
	auto farthest = [] (multiset<int, greater<int>> &s) {
		return s.empty() ? -1 : *s.begin();
	};
	auto farthest_both = [&]() {
		return max(farthest(s1), farthest(s2));
	};
 
	vector<int> ans;
	while (farthest_both() > points_diff) {
		bool choose_s1 = farthest(s1) > farthest(s2);
		auto &s_far = choose_s1 ? s1 : s2;
		auto &s_near = choose_s1 ? s2 : s1;
 
		int value = *s_far.begin();
		int complem = value - points_diff;
		if (!s_near.count(complem)) 
			return false;
 
		s_far.erase(s_far.find(value));
		s_near.erase(s_near.find(complem));
 
		if (choose_s1) 
			ans.push_back(p1 + value);
		else
			ans.push_back(p2 - value);
	}
 
	vector<int> left1, left2;
	for (auto i : s1)
		left1.push_back(i);
	for (auto i : s2)
		left2.push_back(i);
	sort(left1.begin(), left1.end());
	sort(left2.rbegin(), left2.rend());
 
	for (int i = 0; i < left1.size(); i++)
		if (left1[i] + left2[i] != points_diff)
			return false;
 
	for (auto i : left1)
		ans.push_back(i);
 
	sort(ans.begin(), ans.end());
	int sh = max(-ans[0], 0);
	p1 += sh, p2 += sh;
	for (auto &i : ans)
		i += sh;
 
	cout << "YES\n";
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
	cout << p1 << ' ' << p2 << '\n';
	return true;
}
 
void solve() {
	cin >> n;
	d1.resize(n);
	d2.resize(n);
	for (auto &d : d1)
		cin >> d;
	for (auto &d : d2)
		cin >> d;
 
	int dist1 = d1[0];
	for (auto dist2 : d2) {
		if (work(dist1 + dist2))
			return;
		if (work(abs(dist1 - dist2)))
			return;
	}
 
	cout << "NO\n";
}
 
int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();
 
	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}
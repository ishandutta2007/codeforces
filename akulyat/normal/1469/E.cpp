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
const int sz = 20;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
string s;
bool viv = false;

string i_to_s(int val) {
	string res;
	for (int i = sz - 1; i >= 0; i--)
		res += char('0' + ((val >> i) & 1));
	return res;
}

int s_to_i(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); i++)
		res <<= 1, res += (s[i] == '1');
	return res;
}

void inv(string &s) {
	for (auto &i : s)
		if (i == '0')
			i = '1';
		else
			i = '0';
}

void solve() {
	cin >> n >> k;
	cin >> s;
	set<int> bad;
	vector<int> p = {0};
	for (int i = 0; i < n; i++)
		p.push_back(p.back() + (s[i] == '1'));
	for (int i = k; i <= n; i++) {
		int l = i - k, r = i;
		int fl = max(l, r - sz);
		string ss;
		for (int j = fl; j < r; j++)
			ss += s[j];
		inv(ss);
		if (viv) {
			cout << "at " << r << " see " << ss << endl;
		}
		if (p[fl] - p[l] == fl - l)
			bad.insert(s_to_i(ss));
	}
	if (viv) {
		cout << "bad = ";
		for (auto i : bad)
			cout << i << ' ';
		cout << endl;
	}
	int val = 0;
	while (val < (1 << min(k, sz)) && bad.count(val))
		val++;
	if (viv) {
		cout << "val = " << val << endl;
	}
	if (val == (1 << min(k, sz))) 
		return void(cout << "NO\n\n");
	cout << "YES\n";
	auto ans = i_to_s(val);
	if (viv) {
		cout << "ans = " << ans << endl;
	}
	reverse(ans.begin(), ans.end());
	while (ans.size() > k)
		ans.pop_back();
	while (ans.size() < k)
		ans += '0';
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
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
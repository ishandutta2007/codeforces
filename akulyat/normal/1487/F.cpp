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

ll n, ans;
vector<ll> v;
bool viv = false;

void cut(string &s) {
	while (s.size() && s.back() == '0')
		s.pop_back();
}
void norm(string &s) {
	cut(s);
	if (s.empty())
		return;

	if (s.back() < '0') {
		for (auto &i : s) {
			int num = i - '0';
			num = -num;
			i = '0' + num;
		}
	}
	s.push_back('0');
	s.push_back('0');
	for (int i = 0; i < (int)s.size() - 1; i++) {
		while (s[i] < '0')
			s[i] += 10, s[i + 1]--;
		while (s[i] > '9')
			s[i] -= 10, s[i + 1]++;
	}
	cut(s);
}

void dec(string &s) {
	for (auto &i : s)
		i--;
}

int get_ans(string s) {
	if (viv) {
		cout << "solve [" << s << "]" << endl;
	}
	norm(s);
	if (viv) {
		cout << "\tnorm = " << s << endl;
	}
	if (s.empty())
		return 0;
	int ans1 = mod, ans2 = mod;
	if (s.back() <= '6') {
		auto t = s;
		int res = 0;
		int len = t.size();
		while (t.size() == len) {
			res += len;
			dec(t);
			norm(t);
		}
		if (viv)
			cout << "\t\tfell into " << t << endl;
		ans1 = res + get_ans(t);
	}
	if (s.back() >= '6') {
		s.push_back('0');
		int res = s.size();
		dec(s);
		ans2 = res + get_ans(s);
	}
	return min(ans1, ans2);
}

void solve() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	if (viv)	
		cout << "start: " << s << endl;
	int ans = get_ans(s);
	if (viv)
		cout << "\t\t\t\tANS = ";
	cout << ans << '\n';
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
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
string s;
bool viv = false;
set<pair<int, string>> st;

void prepare() {
	for (int i = 0; i < 26; i++) {
		string t;
		t += char('a' + i);
		st.insert({t.size(), t});
		for (int j = 0; j < 26; j++) {
			string t2 = t;
			t2 += char('a' + j);
			st.insert({t2.size(), t2});
			for (int u = 0; u < 26; u++) {
				string t3 = t2;
				t3 += char('a' + u);
				st.insert({t3.size(), t3});
			}
		}
	}	
}

void solve() {
	cin >> n;
	cin >> s;
	vector<pair<int, string>> er;
	for (int i = 0; i < n; i++) {
		string t;
		t += s[i];
		er.push_back({t.size(), t});
		if (i + 1 < n) {
			t += s[i + 1];
			er.push_back({t.size(), t});
			if (i + 2 < n) {
				t += s[i + 2];
				er.push_back({t.size(), t});
			}
		}
	}
	for (auto p : er)
		st.erase(p);
	cout << (*(st.begin())).S << '\n';
	for (auto p : er)
		st.insert(p);
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	prepare();
	while (t--)
		solve();

	return 0;
}
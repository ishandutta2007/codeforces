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
vector<ll> v;
bool viv = false;


void solve() {
	string s;
	cin >> s;
	n = s.size();
	vector<int> cnt(2, 0);
	for (auto i : s)
		cnt[i - '0']++;
	if (cnt[0] == 0) {
		cout << "0\n";
		return;
	}
	while (s.size() && s.back() == '1')
		s.pop_back();
	reverse(s.begin(), s.end());
	while (s.size() && s.back() == '1')
		s.pop_back();
	int nice = true;
	for (auto i : s)
		if (i == '1')
			nice = false;
	if (nice) {
		cout << "1\n";
		return;
	}
	cout << "2\n";
	return;
}

int main() {
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
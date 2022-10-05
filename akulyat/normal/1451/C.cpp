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

ll n, k;
string a, b;
bool viv = false;


void solve() {
	cin >> n >> k;
	cin >> a >> b;
	vector<ll> cnt(27, 0);	
	for (auto &i : a)
		cnt[i - 'a']--;
	for (auto &i : b)
		cnt[i - 'a']++;
	for (int i = 25; i >= 0; i--)
		cnt[i] += cnt[i + 1];
	for (auto i : cnt)
		if (i < 0 || i % k)
			return void(cout << "No\n");
	cout << "Yes\n";
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
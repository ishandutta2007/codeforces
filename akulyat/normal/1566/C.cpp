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
	cin >> n;
	string s, t;
	cin >> s >> t;
	int ans = 0;
	v.clear();
	for (int i = 0; i < n; i++) {
		int a = s[i] - '0';		
		int b = t[i] - '0';		
		int val = 0;
		if (a + b == 1)
			val = 2;
		if (a + b == 0)
			val = 1;
		v.push_back(val);
	}
	ans += v[0];
	for (int i = 1; i < n; i++) {
		ans += v[i];
		if (v[i] + v[i - 1] == 1) {
			ans++;
			v[i] = 9;
		}
	}
	cout << ans << '\n';
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
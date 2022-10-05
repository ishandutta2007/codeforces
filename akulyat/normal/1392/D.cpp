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

ll n;
vector<ll> v;
string s;
bool viv = false;


void solve() {
	cin >> n;
	cin >> s;

	ll pl = -1;
	for (int i = 0; i < n; i++) 
		if (s[i] != s[(i + 1) % n])
			pl = (i + 1) % n;
	if (pl == -1) {
		cout << 1 + ((n - 1) / 3);
		cout << '\n';
		return;
	}

	string t;
	for (int i = 0; i < n; i++)
		t += s[(i + pl) % n];

	v.clear();
	v.resize(n, 1);
	for (int i = 1; i < n; i++)
		if (t[i] == t[i - 1])
			v[i] += v[i - 1];
	v.push_back(1);

	ll ans = 0;
	for (int i = 0; i < n; i++)
		if (v[i + 1] == 1)
			ans += v[i] / 3;
	cout << ans << '\n';
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
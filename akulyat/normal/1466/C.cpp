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

int n;
vector<ll> v;
bool viv = false;
string s;

char get(int l, int r) {
	r++;
	l = max(l, 0);
	r = min(r, n);
	set<char> ins;
	for (int i = l; i < r; i++)
		ins.insert(s[i]);
	char res = 'a';
	while (ins.count(res))
		res++;	
	return res;
}

void solve() {
	cin >> s;
	n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i] == s[i - 1]) {
			s[i] = get(i - 2, i + 2);
			ans++;
		}
		if (i > 1 && s[i] == s[i - 2]) {
			s[i] = get(i - 2, i + 2);
			ans++;
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

	return 0;
}
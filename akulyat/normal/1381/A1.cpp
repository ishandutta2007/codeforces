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
string a, b;
vector<ll> v;
bool viv = false;

void make(string &s, ll len) {
	for (int i = 0; i < len; i++)
		if (s[i] == '0')
			s[i] = '1';
		else
			s[i] = '0';
	reverse(s.begin(), s.begin() + len);
}


void solve() {
	cin >> n;
	cin >> a >> b;

	ll l = 0;
	ll r = n - 1;
	bool tp = false;
	vector<ll> ans;


	for (int i = 0; i < n; i++) {
		ll pl = n - 1 - i;
		if (((b[pl] == a[l]) ^ tp))
			ans.push_back(1);
		ans.push_back(n - i);
		if (l <= r)
			l++;
		else
			l--;
		swap(l, r);
		tp ^= true;		
	}
	if (viv) {
		string s = a;
		for (auto i : ans)
			make(s, i);
		cout << "see: " << a << ' ' << s << ' ' << b << endl; 
	}
	cout << ans.size() << ' ';
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
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
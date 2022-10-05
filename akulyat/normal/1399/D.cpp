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

	set<int> zero, one;	
	ll cnt = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (zero.empty()) {
				one.insert(cnt);
				ans.push_back(cnt);
				cnt++;
			} else {
				auto z = *zero.begin();
				ans.push_back(z);
				zero.erase(z);
				one.insert(z);
			}
		} else {
			if (one.empty()) {
				zero.insert(cnt);
				ans.push_back(cnt);
				cnt++;
			} else {
				auto z = *one.begin();
				ans.push_back(z);
				one.erase(z);
				zero.insert(z);
			}			
		}
	}
	cout << cnt << '\n';
	for (auto i : ans)
		cout << i + 1 << ' ';
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
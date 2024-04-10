#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;


void solve() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	int cnt = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1]) cnt++;	
	}
	cout << (cnt + 1) / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 5e5 + 10;

int a[N];

void solve() {
	string s;
	cin >> s;
	vector<int> v;
	int cur = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == '0') {
			v.push_back(cur);
			cur = 0;
		}	else {
			cur++;
		}
	}
	if (cur) {
		v.push_back(cur);
	}
	sort(v.begin(), v.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < v.size(); i += 2) {
		ans += v[i];
	}
	cout << ans << "\n";
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
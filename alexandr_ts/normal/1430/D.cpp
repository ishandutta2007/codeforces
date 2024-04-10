#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e14;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

vector<int> parse(const string& s) {
	vector<int> v;
	int cur = 1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1]) ++cur;
		else {
			v.push_back(cur);
			cur = 1;
		}
	}
	if (cur) {
		v.push_back(cur);
	}
	return v;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto v = parse(s);

	int cur = 0;
	int ans = 0;
	n = v.size();
	for (int i = 0; i < v.size(); ++i) {
		cur = max(cur, i);
		while (cur < n && v[cur] == 1) {
			++cur;
		}
		if (cur < n) {
			v[cur]--;
			ans++;
		} else {
			ans += (n - i + 1) / 2;
			break;
		}
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
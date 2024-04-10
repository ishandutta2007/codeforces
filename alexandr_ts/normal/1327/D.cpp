#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int p[N];
int c[N];
bool used[N];

int calc(vector<int>& v) {
	int k = v.size();
	vector<int> divs;
	for (int i = 1; i * i <= k; ++i) {
		if (k % i == 0) {
			divs.push_back(i);
			if (i * i != k) {
				divs.push_back(k / i);
			}
		}	
	}

	sort(divs.begin(), divs.end(), greater<int>());
	int ans = INF;
	for (auto d: divs) {
		int steps = k / d;	
		for (int i = 0; i < steps; ++i) {
			set<int> diff;
			for (int j = i; j < k; j += steps) {
				diff.insert(c[v[j]]);
				if (diff.size() >= 2) break;
			}
			/*
			cout << d << " " << i << " " << diff.size() << endl;
			if (d == 2 && i == 2) {
				for (auto x: diff) cout << x << " ";
			}
			cout << endl;
			*/
			if (diff.size() == 1) {
				ans = min(ans, steps);
			}
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}

	fill(used, used + n + 1, false);
	int ans = INF;
	for (int i = 1; i <= n; ++i) {
		if (used[i]) continue;
		int cur = i;
		vector<int> v;
		v.push_back(cur);
		used[cur] = true;
		cur = p[cur];
		while (cur != i) {
			used[cur] = true;
			v.push_back(cur);
			cur = p[cur];
		}
		ans = min(ans, calc(v));	
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
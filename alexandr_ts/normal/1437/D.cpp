#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int a[N];
int h[N];
int cnt[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> cnts = {1, 1};
	for (int i = 2; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			cnts.back()++;
		} else {
			cnts.push_back(1);
		}
	}

	//for (auto x: cnts) cout << x << " ";cout << endl;

	int cnt = 1;
	int cur = 1;
	int i;
	for (i = 2; ; ++i) {
		int sum = 0;
		for (int j = 0; cur < cnts.size() && j < cnt; ++j) {
			sum += cnts[cur];
			cur++;
		}	
		cnt = sum;
		if (cur == cnts.size()) {
			break;	
		}
	}
	cout << i - 1 << "\n";
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
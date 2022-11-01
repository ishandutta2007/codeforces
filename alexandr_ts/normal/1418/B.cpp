#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

int a[N], l[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
		if (!l[i]) {
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (!l[i]) {
			a[i] = v[cur++];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();	
	}
}
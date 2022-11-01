#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e14;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

vector<int> v[30];
vector<int> u[30];

int a[N];
int b[N];

ll inv(int l, int r) {
	if (l == r) {
		return 0;
	}
	int m = (l + r) / 2;
	ll ans = inv(l, m) + inv(m + 1, r);
	int ptr = m + 1;
	vector<int> b;
	for (int i = l; i <= m; ++i) {
		if (ptr == r + 1) {
			b.push_back(a[i]);	
			continue;
		}
		while (ptr <= r && a[i] > a[ptr]) {
			b.push_back(a[ptr]);
			ans += (m + 1 - i);
			++ptr;
		}
		b.push_back(a[i]);
	}
	for (int i = ptr; i <= r; ++i) {
		b.push_back(a[i]);
	}
	copy(b.begin(), b.begin() + r - l + 1, a + l);
	/*
	for (int i = l; i < r; ++i) {
		assert(a[i] < a[i + 1]);
	}
	*/
	return ans;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		v[s[i] - 'a'].push_back(i);
	}

	for (int i = 0; i < 26; ++i) {
		u[i] = v[i];
		for (auto& x: u[i]) {
			x = n - 1 - x;
		}
		reverse(u[i].begin(), u[i].end());
		for (int j = 0; j < (int)u[i].size(); ++j) {
			a[v[i][j]] = u[i][j];
		}
	}
	cout << inv(0, n - 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 10;

int a[N];

string build(int n, int x) {
	string s;
	for (int i = 0; i < n; ++i) {
		int j = i - x;
		bool ok = false;
		if (j >= 0 && a[j]) ok = true;
		j = i + x;
		if (j < n && a[j]) ok = true;
		if (ok) 
			s += '1'; 
		else 
			s += '0';
	}
	return s;
}

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	fill(a, a + n, 1);
	int x;
	cin >> x;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			int j = i - x;
			if (j >= 0) {
				a[j] = 0;
			}
			j = i + x;
			if (j < n) {
				a[j] = 0;
			}
		}	
	}

	if (build(n, x) == s) {
		for (int i = 0; i < n; ++i) {
			cout << (char)(a[i] + '0');
		}
	} else {
		cout << -1;
	}
	cout << "\n";
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
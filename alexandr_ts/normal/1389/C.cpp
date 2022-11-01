#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int M = 21;
const int N = 1e6 + 10;



void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	int ans = n - 1;
	for (int a = 0; a < 10; ++a) {
		for (int b = 0; b < 10; ++b) {
			int len = 0;
			int i = 0;
			bool isa = true;
			while (i < n) {
				while (i < n && (isa && s[i] != ('0' + a) || !isa && s[i] != ('0' + b))) {
					++i;
				}
				if (i < n) {
					++len;
					++i;
					isa = !isa;
				}
			}
			if (!isa && a != b) len--;
			ans = min(ans, n - len);
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
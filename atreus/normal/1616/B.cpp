#include <bits/stdc++.h>
#define bit(n, k) (((n)>>(k))&1)
using namespace std;

const int maxn = 1e5 + 1;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i + 1 == n || s[i] < s[i + 1] || (s[i] == s[i + 1] and i == 0)) {
			for (int j = 0; j <= i; j++)
				cout << s[j];
			for (int j = i; j >= 0; j--)
				cout << s[j];
			cout << '\n';
			break;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}
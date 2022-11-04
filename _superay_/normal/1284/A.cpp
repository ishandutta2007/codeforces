#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[22], t[22];
string y[405];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= m; i++) cin >> t[i];
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		x = (x - 1) % (n * m) + 1;
		cout << s[(x - 1) % n + 1] << t[(x - 1) % m + 1] << endl;
	}
	return 0;
}
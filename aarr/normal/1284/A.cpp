#include <bits/stdc++.h>
using namespace std;

string s[25];
string t[25];

int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> t[i];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int y;
		cin >> y;
		y--;
		cout << s[y % n] + t[y % m] << '\n';
	}
	return 0;
}
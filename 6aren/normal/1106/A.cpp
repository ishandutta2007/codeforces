#include <bits/stdc++.h>

using namespace std;

int ans = 0, n;

string s[505];

bool check(int i, int j) {
	return (s[i][j] == 'X' && s[i - 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i + 1][j + 1] == 'X');
}

int main() {
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	} 
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (check(i, j)) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
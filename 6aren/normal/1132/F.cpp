#include <bits/stdc++.h>

using namespace std;

string s;

vector <int> a;

int f[505][505];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int n;
	cin >> n;
	cin >> s;
	a.push_back(s[0] - 'a');
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			a.push_back(s[i] - 'a');
		}
	}
	n = a.size();
	for (int i = 0; i < n; i++) {
		f[i][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			f[j][i + j] = min(f[j][i + j - 1], f[j + 1][i + j]) + 1;
			for (int k = j; k < j + i; k++) {
				if (a[k] == a[j + i]) {
					f[j][i + j] = min(f[j][i + j], f[j][k - 1] + f[k][i + j - 1]);
				}
			}
		}
	}
	cout << f[0][n - 1];
	return 0;
}
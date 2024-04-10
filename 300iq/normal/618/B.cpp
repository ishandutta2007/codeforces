#include <bits/stdc++.h>

using namespace std;

int a[50][50];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	bool logic = false;
	for (int i = 0; i < n; i++) {
		int f = 0;
		for (int j = 0; j < n; j++)
			f = max(f, a[j][i]);
		if (f == n - 1 && !logic) f++, logic = true;
		cout << f << " ";
	}
}
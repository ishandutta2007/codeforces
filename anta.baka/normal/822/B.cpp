#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	string a, b;
	cin >> n >> m >> a >> b;
	int opt = INT_MAX, opti;
	for(int i = 0; i + n - 1 < m; i++) {
		int c = 0;
		for(int j = 0; j < n; j++)
			c += (a[j] != b[j + i]);
		if(c < opt) {
			opt = c;
			opti = i;
		}
	}
	cout << opt << endl;
	for(int i = 0; i < n; i++)
		if(a[i] != b[opti + i])
			cout << i + 1 << ' ';
}
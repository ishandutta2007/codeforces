#include <bits/stdc++.h>

using namespace std;

map <string, int> M;

int main() {
	int n, m, ret = 0; cin >> n >> m;
	while (n && m && n + m >= 3) {
		if (n > m) n -= 2, m--, ++ret;
		else n--, m -= 2, ++ret;
	}
	cout << ret << endl;
	return 0;
}
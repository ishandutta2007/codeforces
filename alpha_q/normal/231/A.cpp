#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b, c, ret; cin >> n;
	ret = 0; while (n--) {
		cin >> a >> b >> c;
		if (a + b + c >= 2) ++ret;
	} cout << ret << endl;
	return 0;
}
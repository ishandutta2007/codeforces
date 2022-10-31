#include <bits/stdc++.h>
using namespace std;
#define int long long
int calc(int m, int b, int x) {
	return ((m*b - m*x + 1)*(x + 1)*(m*b - m*x + x)) / (int)2;
}
signed main() {
	int m, b;
	cin >> m >> b;
	
	int res = 0;
	for (int i = 0; i <= b; i++) {
		res = max(res, calc(m, b, i));
	}
	cout << res << endl;
}
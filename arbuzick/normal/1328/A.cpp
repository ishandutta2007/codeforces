#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		if (a % b == 0)
			cout << 0 << endl;
		else
			cout << a / b * b + b-a << endl;
	}
	return 0;
}
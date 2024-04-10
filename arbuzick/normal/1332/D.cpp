#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	cout << 3 << ' ' << 3 << endl;;
	int a[3][3];
	a[2][0] = 0;
	a[2][1] = 0;
	a[0][0] = 262143;
	a[1][0] = k;
	a[1][1] = k;
	a[1][2] = 262143;
	a[2][2] = k;
	a[0][1] = k ^ 262143;
	a[0][2] = k ^ 262143;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			cout << a[j][i] << ' ';
		cout << endl;
	}
	return 0;
}
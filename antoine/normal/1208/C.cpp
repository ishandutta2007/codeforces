#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int a[1009][1009];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	int val = 0;
	for (int i = 0; i < n; i += 4)
		for (int j = 0; j < n; j += 4)
			for (int x = 0; x < 4; ++x)
				for (int y = 0; y < 4; ++y)
					a[i + x][j + y] = val++;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cout << a[i][j] << " \n"[j == n - 1];

	return 0;
}
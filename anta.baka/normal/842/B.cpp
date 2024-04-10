#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int R, d, n, ans = 0;
	cin >> R >> d >> n;
	R -= d;
	for(int i = 0; i < n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		int z = x * x + y * y;
		if(z >= (r + R) * (r + R) && z <= (R + d - r) * (R + d - r)) ans++;
	}
	cout << ans;
}
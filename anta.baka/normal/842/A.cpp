#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for(int a = l; a <= r; a++)
		if(a % k == 0) {
			int b = a / k;
			if(x <= b && b <= y) return cout << "YES", 0;
		}
	cout << "NO";
}
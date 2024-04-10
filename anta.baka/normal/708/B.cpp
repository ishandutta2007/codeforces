#include <bits/stdc++.h>

using namespace std;

int main() {
	int a00, a01, a10, a11;
	cin >> a00 >> a01 >> a10 >> a11;
	if(a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
		cout << 0;
		return 0;
	}
	int x = 0, y = 0;
	if(a01 != 0 || a10 != 0) {
	    x = 1; y = 1;
	}
	while(1ll * x * (x-1) / 2 < a00)
		x++;
	while(1ll * y * (y-1) / 2 < a11)
		y++;
	if(1ll * x * (x-1) / 2 != a00 || 1ll * y * (y-1) / 2 != a11 || 1ll * x * y != a10 + a01) {
		cout << "Impossible";
		return 0;
	}
	for(int i = 0, n = x + y; i < n; i++)
		if(x > 0 && a01 >= y) {
			cout << 0;
			a01 -= y;
			x--;
		} else {
		    cout << 1;
			y--;
		}
}
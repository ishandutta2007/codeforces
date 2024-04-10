#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int r, h;
	cin >> r;
	cin >> h;
	int ans = (h / r) * 2 + 1;
	if ((h % r) * 2 >= r) {
		ans++;
		double x = h % r, y = (sqrt(3) / 2) * r;
		//cout << x << " " << y << endl;
		if(x >= y)
			ans++;
	}
		
	cout << ans;
	return 0;
}
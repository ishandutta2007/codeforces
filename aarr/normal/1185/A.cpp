#include <iostream>
#include <algorithm>
using namespace std;

long long a[5];
int main() {
	long long d, ans = 0;
	cin >> a[0];
	cin >> a[1];
	cin >> a[2];
	cin >> d;
	sort(a, a + 3);
	if (a[1] - a[0] < d)
		ans += d - a[1] + a[0];
	if (a[2] - a[1] < d)
		ans += d - a[2] + a[1];
	cout << ans;
	return 0;
}
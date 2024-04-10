#include <iostream>

using namespace std;

int main() {
	int n, d, s;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s >> d;
		if (ans < s)
			ans = s;
		else if (s % d > ans % d)
			ans = ans + s % d - ans % d;
		else
			ans = ans + d - ans % d + s % d;
	}
	cout << ans << endl;
}
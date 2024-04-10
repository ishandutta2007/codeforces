#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
	long long s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		int x;
		cin >> x;
		if (c == '+') {
			s += x;
		}
		else {
			if (s >= x) {
				s -= x;
			}
			else {
				ans++;
			}
		}
	//	cout << 73 << " " << c << " " << x << endl;
	}
	cout << s << " " << ans << endl;
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int n, d, ans = 0, x = 0;
	cin >> n >> d;
	for (int i = 1; i <= d; i++) {
		bool b = false;
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '0')
				b = true;
		}
		if (b)
			x++;
		else
			x = 0;
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
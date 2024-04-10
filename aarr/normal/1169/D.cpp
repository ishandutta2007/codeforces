#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	
	long long ans = 1ll * n * (n - 1) / 2;
	for (int l = 0; l < s.size(); l++) {
		for (int r = l + 1; r < s.size() && r < l + 11; r++) {
			bool b = false;
			for (int x = l; x < r; x++) {
				for (int k = 1; x + 2 * k <= r; k++) {
					if (s[x] == s[x + k] && s[x] == s[x + 2 * k])
						b = true;
				}
			}
			if (!b)
				ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
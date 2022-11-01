#include <iostream>
using namespace std;

string s[105];
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int x = 0;
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'C') {
				x++;
			}
		}
		ans += x * (x - 1) / 2;
	}
	for (int j = 0; j < n; j++) {
		int x = 0;
		for (int i = 0; i < n; i++) {
			if (s[i][j] == 'C') {
				x++;
			}
		}
		ans += x * (x - 1) / 2;
	}
	cout << ans;
	return 0;
}
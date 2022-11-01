#include <iostream>
using namespace std;

string s[15];
bool mark[15];
bool b[15];

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, ans = 0;
		cin >> n;
		for (int j = 0; j < 10; j++) {
			b[j] = false;
		}
		for (int j = 0; j < n; j++) {
			mark[j] = false;
			cin >> s[j];
			for (int k = 0; k < j; k++) {
				if (s[j] == s[k]) {
					mark[j] = true;
				}
			}
			b[s[j][0] - '0'] = true;
		}
		for (int j = 0; j < n; j++) {
			if (mark[j]) {
				for (int k = 0; k < 10; k++) {
					if (!b[k]) {
						s[j][0] = '0' + k;
						b[k] = true;
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << endl;
		for (int j = 0; j < n; j++) {
			cout << s[j] << endl;
		}
	}
	return 0;
}
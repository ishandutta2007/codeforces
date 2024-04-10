#include <iostream>
using namespace std;

int cnt[15];
int main() {
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - '0']++;
	}
	int x = k;
	while (x < n && s[x] == s[x - k]) {
		x++;
	}
	if (x == n) {
		cout << n << endl;
		cout << s << endl;
	}
	else {
		if (s[x] < s[x - k]) {
			for (int i = k; i < n; i++) {
				s[i] = s[i - k];
			}
			cout << n << endl;
			cout << s << endl;
		}
		else {
			for (int i = k - 1; i >= 0; i--) {
				if (s[i] != '9') {
					s[i]++;
					for (int j = i + 1; j < k; j++) {
						s[j] = '0';
					}
					for (int i = k; i < n; i++) {
						s[i] = s[i - k];
					}
					cout << n << endl << s << endl;
					return 0;
				}

			}
			cout << n << endl;
			for (int i = 0; i < n; i++) {
				cout << '9';
			}
		}
	}
	return 0;
}
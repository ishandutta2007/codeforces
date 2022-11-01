#include <iostream>
#include <cmath>
using namespace std;

int a[100 * 1000 + 5];

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n;
		string s;
		cin >> n >> s;
		if (n == 2 && s[1] <= s[0]) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n2\n";
			cout << s[0] << " ";
			for (int i = 1; i < s.size(); i++) {
				cout << s[i];
			}
			cout << '\n';
		}
	}
	return 0;
}
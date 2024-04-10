#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string* a = new string[n];
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp >= 12) a[i] = "YES";
		else {
			switch (tmp) {
			case 0: case 3: case 6: case 7: case 9: case 10:
				a[i] = "YES";
				break;
			default:
				a[i] = "NO";
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << '\n';
	}
	return 0;
}
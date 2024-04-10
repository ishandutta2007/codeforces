#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool b = false;
			if (i % 2)
				b = true;
			if (j == m && i % 4 == 2)
				b = true;
			if (j == 1 && i % 4 == 0)
				b = true;
			if (b)
				cout << '#';
			else
				cout << '.';
		}
		cout << endl;
	}
	return 0;
}
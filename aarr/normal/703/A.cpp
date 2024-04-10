#include <iostream>
using namespace std;

int main() {
	int n, x = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			x++;
		if (a < b)
			x--;
	}
	if (x > 0)
		cout << "Mishka";
	if (x < 0)
		cout << "Chris";
	if (x == 0)
		cout << "Friendship is magic!^^";
	return 0;
}
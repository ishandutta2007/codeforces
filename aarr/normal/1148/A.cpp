#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a == b)
		cout << 2ll * c + 2ll * a;
	else
		cout << 2ll * min(a, b) + 1 + 2ll * c;
	return 0;
}
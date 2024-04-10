#include <iostream>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	if ((n / k) % 2) {
		cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}
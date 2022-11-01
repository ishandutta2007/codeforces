#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (m >= n && k >= n)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

void right(int n) {
	for (int i = 1; i < n; ++i)
		cout << i << ' ' << i + 1 << '\n';
}

void wrong(int n) {
	if (n < 6) {
		cout << "-1\n";
		return;
	}
	for (int i = 2; i < n - 1; ++i)
		cout << "1 " << i << '\n';
	cout << "2 " << n - 1 << '\n';
	cout << "2 " << n << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	wrong(n);
	right(n);
	return 0;
}
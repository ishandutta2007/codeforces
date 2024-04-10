#include <iostream>
using namespace std;

void Main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cout << (char) ('a' + i % k);
	}
	cout << endl;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		Main();
	}
	return 0;
}
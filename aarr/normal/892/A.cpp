#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


const int N = 100 * 1000 + 5;

int a[N];
int b[N];

int main() {
	int n;
	cin >> n;
	long long s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(b, b + n);
	if (b[n - 2] + b[n - 1] >= s) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	vector<int> a(n);
	int m;
	m = 0;
	for (int i = 0; i < n; ++i) {
		a[i] = b[i] + m;
		if (a[i] > m)
			m = a[i];
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
}
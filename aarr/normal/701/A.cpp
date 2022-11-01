#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> a[105];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n / 2; i++) {
		cout << a[i].second << " " << a[n - i + 1].second << endl;
	}
	return 0;
}
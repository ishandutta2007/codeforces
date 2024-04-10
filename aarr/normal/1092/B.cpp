#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;

int a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 1; i < n; i += 2)
		ans += a[i] - a[i - 1];
	cout << ans << endl;
	return 0;
}
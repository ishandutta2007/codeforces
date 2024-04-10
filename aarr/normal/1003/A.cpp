#include <iostream>
using namespace std;

const int N = 105;

int a[N];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
		ans = max(ans, a[x]);
	}
	cout << ans << endl;
	return 0;
}
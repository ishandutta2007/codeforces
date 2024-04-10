#include <iostream>
using namespace std;


const int N = 200 * 1000 + 5;
int a[N];
int main() {
	int n, ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i && a[i] != a[i - 1]) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
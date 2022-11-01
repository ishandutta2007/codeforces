#include <iostream>
using namespace std;

const int N = 105;

int a[N];
int ans[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
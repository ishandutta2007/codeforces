#include <iostream>
using namespace std;

int a[5];
int b[5005][5];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x]++;
		b[a[x]][x] = i;
	}
	int ans = min(min(a[1], a[2]), a[3]);
	cout << ans << endl;
	for (int i = 1; i <= ans; i++) {
		cout << b[i][1] << " " << b[i][2] << " " << b[i][3] << endl;
	}
	return 0;
}
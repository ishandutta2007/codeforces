#include <iostream>
using namespace std;

int main() {
	int n, m, z, ans = 0;
	cin >> n >> m >> z;
	for (int i = 1; i <= z; i++) {
		if (i % n == 0 && i % m == 0)
			ans++;
	}
	cout << ans;
	return 0;
}
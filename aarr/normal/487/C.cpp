#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;
int n;

bool mark[N];
vector <int> vec;

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= n;
	if (y % 2) {
		ans *= x;
		ans %= n;
	}
	return ans;
}


int main() {
	cin >> n;
	if (n == 4) {
		cout << "YES\n1 3 2 4";
		return 0;
	}
	if (n == 1) {
		cout << "YES\n1";
		return 0;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n1\n";
	for (int i = 2; i <= n; i++) {
		long long ans = 1ll * po(i - 1, n - 2) * i;
		ans %= n;
		if (ans == 0) {
			ans += n;
		}
		cout << ans << '\n';
	}
	return 0;
}
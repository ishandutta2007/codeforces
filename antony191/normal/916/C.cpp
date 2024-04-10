#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

const int pr = 100003;
const int inf = 1e8;

int main() {
	//ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	if (n == 2) {
		cout << 2 << ' ' << 2 << '\n';
		cout << 1 << ' ' << 2 << ' ' << 2 << '\n';
		return 0;
	}
	cout << 2 << ' ' << pr << '\n';
	cout << 1 << ' ' << n << ' ' << 2 << '\n';
	cout << 1 << ' ' << 2 << ' ' << pr - (n - 1) << '\n';
	for (int i = 3; i <= n - 1; ++i) {
		printf("%d %d %d\n", 1, i, 1);
	}
	m -= n - 1;
	int i = 2, j = 3;
	while (m > 0) {
		printf("%d %d %d\n", i, j, inf);
		++j;
		if (j > n) {
			++i;
			j = i + 1;
		}
		--m;
	}
	//system("pause");
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, k, A, B, ans = 0;
	cin >> n >> k >> A >> B;
	if (k == 1) {
		cout << (n - 1) * A;
		return 0;
	}
	while (n >= k) {
		if (n%k) {
			ans += (n%k) * A;
			n -= n%k;
		}
		else {
			ans += min(B, (n - n / k) * A);
			n /= k;
		}
	}
	ans += (n - 1) * A;
	cout << ans;
	return 0;
}
#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;

	int res = 1;
	while(n > 1) {
		int rep = min(n - n/3, n - n/2);
		assert(rep > 0);
		while(rep--) {
			cout << res << ' ';
		}
		if(n - n/3 <= n - n/2) {
			n /= 3;
			res *= 3;
		} else {
			n /= 2;
			res *= 2;
		}
	}
	assert(n == 1);
	cout << res << '\n';
	return 0;
}
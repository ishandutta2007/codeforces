#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 1e5 + 4;

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		ld n;
		cin >> n;
		if (n == 0) {
			cout << "Y 0 0 \n";
			continue;
		}
		if (n * n - 4 * n < 0) {
			cout << "N \n";
			continue;
		}
		ld b = 1.0 * (n + 1.0 * sqrt (n * n - 4 * n)) / 2;
		ld a = n / b;
		cout << "Y " << fixed << setprecision(10) << a << " " << b << '\n';
	}
}
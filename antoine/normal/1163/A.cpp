#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	n -= m;

	if (!n) {
		cout << 0;
		return 0;
	}
	if (m <= 1) {
		cout << 1;
		return 0;
	}

	if (n / m == 0)
		cout << n % m;
	else
		cout << m;
	return 0;
}
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
	ll n;
	cin >> n;
	if (n % 2 == 0)
		return cout << n / 2 << endl, 0;
	ll k = 0;
	for (int i = 2; i <= sqrt (n); i++) {
		if (n % i == 0) {
			k = i;
			break;
		}
	}
	if (k == 0)
		k = n;
	n -= k;
	return cout << n / 2 + 1 << endl, 0;
}
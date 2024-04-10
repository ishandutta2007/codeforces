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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--  ){
		ll p, q, b;
		cin >> p >> q >> b;
		for(;;) {
			b = gcd(b, q);
			if (b == 1)
				break;
			do {
				q /= b;
			} while (q%b == 0);
		}
		cout << (p%q == 0 ? "Finite" : "Infinite") << '\n';
	}
	return 0;
}
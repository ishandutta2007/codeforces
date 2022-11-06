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

int query(ll x, ll y) {
	cout << x << ' ' << y << endl;
	int ans;
	cin >> ans;
	if (!ans) exit(0);
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll loA = 1, mA, hiA;
	ll loB = 1, mB, hiB;
	cin >> hiA;
	mA = (mB = (hiB = hiA));

	for (;;) {
		const long double areaA = (long double)(hiA - mA) * (mB - loB + 1);
		const long double areaB = (long double)(hiB - mB) * (mA - loA + 1);
		const long double areaC = (long double)(mA - loA + 1) * (mB - loB + 1);
		const ll midA = areaA > areaB + areaC + 999 ? mA : (loA + mA) >> 1;
		const ll midB = areaB > areaA + areaC + 999 ? mB : (loB + mB) >> 1;
		const int ans = query(midA, midB);
		if (ans == 3) {
			mA = midA - 1;
			mB = midB - 1;
		}
		else if (ans == 1)
			loA = midA + 1;
		else if (ans == 2)
			loB = midB + 1;
		else
			assert(false);

		if (loA > mA) {
			hiB = mB;
			mA = hiA;
			mB = hiB;
		}
		if (loB > mB) {
			hiA = mA;
			mA = hiA;
			mB = hiB;
		}
	}
	return 0;
}
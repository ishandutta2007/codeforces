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
typedef long double ld;

ld n, H;

bool f(ld mid) {
	if (mid <= H)
		return mid * (mid + 1) / 2 >= n;
	ld sum = H * (H - 1) / 2;
	mid -= (H - 1);
	sum += H * mid;

	ld highest = (long long)(mid - .9) / 2;
	if ((long long)mid & 1) {
		sum += highest;
		highest--;
		mid--;
	}
	sum += highest * (highest + 1);
	return sum + .1 >= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> H;
	ld lo = 1, hi = n;
	while (lo + .1 < hi) {
		ld mid = ((long long)lo + (long long)hi) / 2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << (long long)lo;
	return 0;
}
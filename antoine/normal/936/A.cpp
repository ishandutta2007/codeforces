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

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed;
	cout << setprecision(10);
	
	ll k, d, t;

	cin >> k >> d >> t;
	d *= (k + d - 1) / d;
	
	ll perCycleProgress = k * 2 + (d - k);
	ll cycleCount = (2 * t) / perCycleProgress;
	
	double ans = cycleCount * d;
	ll progressLeft = 2 * t - perCycleProgress * cycleCount;
	if (progressLeft <= k * 2)
		ans += (double)progressLeft / 2;
	else {
		ans += (double)k;
		progressLeft -= k * 2;
		ans += progressLeft;
	}
	cout << ans;
	return 0;
}
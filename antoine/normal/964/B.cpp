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
#include <assert.h>
#include <numeric>

using namespace std;
typedef long long ll;


// 9:36

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, A, B, C, T;
	cin >> n >> A >> B >> C >> T;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		ans += A + (T - t) * max(0, C - B);
	}
	cout << ans;
	return 0;
}
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	ll w, h, k;
	cin >> w >> h >> k;
	ll ans = 0;
	while(k--) {
		ans += 2*w + 2*h - 4;
		w -= 4;
		h -= 4;
	}
	cout << ans;

	return 0;
}
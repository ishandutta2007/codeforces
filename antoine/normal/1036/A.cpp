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

ll f(ll n, ll m, ll k) {
	if (k < m) return -1;
	if ((n + m) & 1) return k - 1;
	return k - ((k - m) & 1 ? 2 : 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, k;
	cin >> n >> k;
	cout << (k + n - 1) / n;
	return 0;
}
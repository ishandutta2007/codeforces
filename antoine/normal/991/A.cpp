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
	cin.tie(0);
	cout.tie(0);

	int n, a, b, c;
	cin >> a >> b >> c >> n;
	int d = a + b - c;
	if (a > n || b > n || c > min(a, b) || d < 0 || d >= n)
		cout << -1;
	else
		cout << n - d;

	return 0;
}
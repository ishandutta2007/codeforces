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

void repeat(int x, int t) {
	cout << x;
	if (--t)
		repeat(x, t);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, x;
	cin >> a >> b >> x;

	int num0 = a >= b ? (x + 2) / 2 : (x + 1) / 2;
	int num1 = a >= b ? (x + 1) / 2 : (x + 2) / 2;

	vector<int> v0(num0, 1), v1(num1, 1);
	v0.back() = a - (num0 - 1);
	v1.back() = b - (num1 - 1);


	for (int turn = a >= b ? 0 : 1; !v0.empty() || !v1.empty(); turn ^= 1) {
		if (turn == 0) {
			repeat(0, v0.back());
			v0.pop_back();
		}
		else {
			repeat(1, v1.back());
			v1.pop_back();
		}
	}
	return 0;
}
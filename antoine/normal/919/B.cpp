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


int n, m;
vector<int> adj[(int)3e5];
string s;

bool f(int x) {
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum == 10;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	for (int i = 1;; ++i)
		if (f(i) && !(--k)) {
			cout << i;
			return 0;
		}
	return 0;
}
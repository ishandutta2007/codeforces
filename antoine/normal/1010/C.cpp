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


int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int g = 0;
	while (n--) {
		int x;
		cin >> x;
		g = gcd(x, g);
	}

	set<int> res;
	for(int i = 0; i < k; ++i)
		res.insert((ll)g * i % k);
	cout << res.size() << endl;
	for (auto &&x : res)
		cout << x << endl;
	return 0;
}
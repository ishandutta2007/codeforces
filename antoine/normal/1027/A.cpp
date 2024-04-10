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

string f() {

	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		if (!set<int>{-2, 0, 2}.count(s[i] - s[n - 1 - i]))
			return "NO";
	return "YES";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--)
		cout << f() << '\n';
	return 0;
}
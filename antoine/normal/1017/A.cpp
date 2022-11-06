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

void solve() {
	int n;
	cin >> n;
	vector<int> scores(n);
	for (int i = 0; i < n; ++i) {
		int a[4];
		for (int j = 0; j < 4; ++j)
			cin >> a[j];
		scores[i] = accumulate(a, a + 4, 0);
	}
	int rank = 1;
	for (int i = 1; i < n; ++i)
		rank += scores[i] > scores[0];
	cout << rank;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}
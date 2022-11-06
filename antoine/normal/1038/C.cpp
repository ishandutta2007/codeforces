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

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	static ll score[2];
	for (int turn = 0; !a.empty() || !b.empty(); turn ^= 1) {
		vector<int> &x = turn ? b : a;
		vector<int> &y = turn ? a : b;
		if (y.empty() || (!x.empty() && x.back() > y.back())) {
			score[turn] += x.back();
			x.pop_back();
		}
		else {
			y.pop_back();
		}
	}
	cout << score[0] - score[1] << endl;
	return 0;
}
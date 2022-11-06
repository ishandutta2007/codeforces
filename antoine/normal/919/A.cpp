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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	double ans = numeric_limits<double>::max();
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		ans = min(ans, (double)a / b);
	}
	cout << fixed << setprecision(10) << ans *m;
	return 0;
}
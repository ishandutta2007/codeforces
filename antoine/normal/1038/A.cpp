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

	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<int> occ(26, 0);
	for (char c : s)
		++occ[c - 'A'];
	
	const int ans = *min_element(occ.begin(), occ.begin() + k) * k + accumulate(occ.begin() + k, occ.end(), 0);
	cout << ans << endl;
	return 0;
}
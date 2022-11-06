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

int ceil(int n, int k) {
	return (n + k - 1) / k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n, k;
	cin >> n >> k;

	const int ans = ceil(n, 2 * k + 1);
	string s;
	for (int rep = 0; rep < ans; ++rep)
		s += string(k, ' ') + "." + string(k, ' ');

	int i = 0, j = s.size() - 1;
	while (j - i + 1 > n) {
		if (s[i] == ' ')
			++i;
		else if (s[j] == ' ')
			--j;
		else
			assert(false);
	}
	cout << ans << '\n';
	s.erase(s.begin() + j + 1, s.end());
	s.erase(s.begin(), s.begin() + i);
	for(i = 0; i < s.size(); ++i)
		if (s[i] == '.')
			cout << i + 1 << ' ';

	return 0;
}
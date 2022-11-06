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

#define PROB_NAME "A-large-practice" // undefine if using console i/o
#define INPUT_DIR "D:\\OneDrive - Murex\\Downloads\\"
#define OUTPUT_DIR INPUT_DIR

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(11);

	string s;
	cin >> s;
	string dp = s;
	for (int i = s.size() - 2; i >= 0; --i)
		dp[i] = min(dp[i], dp[i + 1]);

	string res = "";
	string t;
	int cursor = 0;
	while (res.size() < s.size()) {
		if (!t.empty() && (cursor == s.size() || t.back() <= dp[cursor])) {
			res += t.back();
			t.pop_back();
		}
		else
			t += s[cursor++];
	}
	cout << res;
	return 0;
}
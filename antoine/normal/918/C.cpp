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

const int MaxK = 40;
const int MaxS = MaxK * 50;

int dp[MaxK + 1][MaxS + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		int sum = 0;
		int q = 0;
		for (int j = i; j < s.size(); ++j) {
			if (s[j] == '(')
				++sum;
			else if (s[j] == ')')
				--sum;
			else if (s[j] == '?') {
				--sum;
				++q;
			}
			if (sum < 0) {
				if (!q) break;
				q--;
				sum += 2;
			}
			ans += !sum;
		}
	}
	cout << ans;
	return 0;
}
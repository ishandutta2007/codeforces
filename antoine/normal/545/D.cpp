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

const ll Inf = 2e9;
const int K = 50;

ll dp[2][K + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> t(N);
	for (int i = 0; i < N; ++i)
		cin >> t[i];
	sort(t.rbegin(), t.rend());


	for (int j = 0; j < K; ++j)
		dp[N& 1][j] = j ? Inf : 0;
	for (int i = N - 1; i >= 0; --i)
		for (int j = 0; j < K; ++j)
			dp[i & 1][j] = min(dp[~i & 1][j], j && dp[~i & 1][j - 1] <= t[i] ? t[i] + dp[~i & 1][j - 1] : Inf);
	for(int j = K - 1;; --j)
		if (dp[0][j] < Inf) {
			cout << j;
			break;
		}
	return 0;
}
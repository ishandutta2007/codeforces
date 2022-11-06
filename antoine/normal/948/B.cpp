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
#include <stack>
#include <memory>

using namespace std;

const int M = 1e6 + 2;
int spf[M + 2];
int gpf[M + 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);


	memset(spf, 0, sizeof spf);
	for (int i = 2; i <= M; ++i) {
		for (int j = i; j <= M; j += i)
			if (!spf[j])
				spf[j] = i;
	}
	for (int i = 2; i <= M; ++i)
		gpf[i] = spf[i] == i ? i : gpf[i / spf[i]];

	int ans = 1e8;

	int x2;
	cin >> x2;

	for (int x1 = x2 - gpf[x2] + 1; x1 <= x2; ++x1)
		if (spf[x1] != x1)
			ans = min(ans, x1 - gpf[x1] + 1);
	cout << ans;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

const int mod = 1e9 + 7;

bool isSpecial(int n, const int k) {
	if (n <= 1 || k <= 0)
		return n == 1 && !k;
	int c = 0;
	while (n) {
		c += n & 1;
		n >>= 1;
	}
	return isSpecial(c, k - 1);
}

bool subSpe[1001];
int choose[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(choose, 0, sizeof choose);

	for (int i = 0; i <= 1000; ++i) {
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; ++j)
			choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
	}

	string s;
	int k;
	cin >> s >> k;
	if (!k) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i <= 1000; ++i)
		subSpe[i] = isSpecial(i, k - 1);

	int ans = 0;
	int ones = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			int rest = s.size() - i - 1;
			for (int j = 0; j <= rest; ++j)
				if (subSpe[ones + j])
					ans = (ans + choose[rest][j]) % mod;
			++ones;
		}
	}
	ans = (ans - subSpe[1] + mod) % mod;
	ans = (ans + subSpe[ones]) % mod;
	cout << ans;

	return 0;
}
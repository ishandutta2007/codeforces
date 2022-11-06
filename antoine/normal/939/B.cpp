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

using namespace std;

const long long mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, k;
	cin >> n >> k;

	long long best = -1;
	long long choice1 = 0;
	long long choice2 = 0;

	for (int i = 1; i <= k; ++i) {
		long long a;
		cin >> a;
		if ((n / a) *  a > best) {
			best = (n / a) * a;
			choice1 = i;
			choice2 = n / a;
		}
	}
	cout << choice1 << ' ' << choice2;
	return 0;
}
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

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, k, winner, count = 0;
	cin >> n >> k >> winner;
	for (int i = 1; i < n && count < k; ++i) {
		int a;
		cin >> a;
		if (a > winner) {
			winner = a;
			count = 1;
		}
		else
			++count;
	}
	cout << winner;
	return 0;
}
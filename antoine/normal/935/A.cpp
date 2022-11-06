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

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int l = 1; l < n; ++l)
		ans += !(n%l);
	cout << ans;

	return 0;
}
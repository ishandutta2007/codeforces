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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n;
	cin >> n;
	long long ans = 0;
	for(int c = 1; c <= n; ++c)
		for (int b = 1; b <= n; ++b) {
			int a = b^c;
			ans += 1 <= a && a <= b && b <= c && c <= n && a + b > c;
		}
	cout << ans;
	return 0;
}
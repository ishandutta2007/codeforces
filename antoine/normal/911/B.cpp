#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int a[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;
	int x = -111;
	for (int p = 1; p < n; ++p) {
		int curr1 = floor((double)a / p);
		int curr2 = floor((double)b / (n-p));
		int curr = min(curr1, curr2);
		x = max(x, curr);
	}
	cout << x;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <set>
#include <map>


using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	a[0] = 1;
	a[n + 1] = 1000000;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int imax = 1000000;
	for (int i = 1; i < n + 2; ++i)
		if (max(a[i - 1] - a[0], a[n + 1] - a[i]) < imax)
			imax = max(a[i - 1] - a[0], a[n + 1] - a[i]);
	cout << imax;
	return 0;
}
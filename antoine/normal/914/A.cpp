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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<bool> f(1e6 + 5, false);
	for (int i = 0; i*i < f.size(); ++i)
		f[i*i] = 1;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for(auto &&x : a)
		if (x < 0 || !f[x]) {
			cout << x;
			return 0;
		}
	return 0;
}
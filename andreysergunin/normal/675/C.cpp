#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex>
#include <ctime>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int main() {
	int n;
	cin >> n;

	vector<long long> a(n);
	vector<long long> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i == 0)
			b[i] = a[i];
		else
			b[i] = b[i - 1] + a[i];
	}
	sort(all(b));
	int ans = 1;
	int cur = 1;
	for (int i = 1; i < n; ++i) {
		if (b[i] == b[i - 1])
			++cur;
		else {
			ans = max(ans, cur);
			cur = 1;
		}
	}
	ans = max(ans, cur);
	cout << n - ans << endl;

    return 0;
}
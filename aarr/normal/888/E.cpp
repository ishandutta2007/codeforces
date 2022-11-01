#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 37;

int a[N];
vector <int> vec;

long long get(long long x, int y) {
	return (x >> y) & 1;
}

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int p = n / 2;
	vec.push_back(m);
	vec.push_back(-1);
	for (int mask = 0; mask < (1 << p); mask++) {
		int sm = 0;
		for (int i = 0; i < p; i++) {
			if (get(mask, i)) {
				sm += a[i];
				sm %= m;
			}
		}
	//	cout << "51 " << sm << endl;
		vec.push_back(sm);
	}
	sort(vec.begin(), vec.end());
	for (long long mask = 0; mask < (1ll << n); mask += (1ll << p)) {
		int sm = 0;
		for (int i = p; i < n; i++) {
			if (get(mask, i)) {
				sm += a[i];
				sm %= m;
			}
		}
		int x = lower_bound(vec.begin(), vec.end(), m - sm) - vec.begin() - 1;
	//	cout << "52 " << sm << " " << vec[x] << endl;
		ans = max(ans, sm + vec[x]);
	}
	cout << ans;
	return 0;
}
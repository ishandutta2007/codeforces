#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[100 * 1000 + 5];
vector <char> vec;

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	int t = 0;
	for (int i = 0; i < k; i++, t++) {
		if (t > 0 && vec[t] - vec[t - 1] == 1) {
			t++;
		}
		if (t == vec.size()) {
			cout << -1;
			return 0;
		}
		else {
			ans += vec[t] - 'a' + 1;
		}
	}
	cout << ans;
	return 0;
}
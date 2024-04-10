#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;
vector <int> vec[N];


int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 2; j * j <= x; j++) {
			int c = 0;
			while (x % j == 0) {
				x /= j;
				c++;
			}
			vec[j].push_back(c);
		}
		vec[x].push_back(1);
	}
	long long ans = 1;
	for (int i = 2; i < N; i++) {
		sort(vec[i].begin(), vec[i].end());
		if (vec[i].size() >= n - 1) {
			int t;
			if (vec[i].size() == n) {
				t = 1;
			}
			else {
				t = 0;
			}
			for (int j = 0; j < vec[i][t]; j++) {
				ans *= i;
				
			}
		}
	}
	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int Sum(int n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> res;
	for (int i = 0; i < 10000; i++) {
		if (N - i <= 0) break;
		if (Sum(N - i) + N - i == N) {
			res.push_back(N - i);
		}
	}
	sort(res.begin(), res.end());

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}
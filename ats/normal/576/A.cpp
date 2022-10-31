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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> X(N + 1, 0);
	vector<int> res;
	for (int i = 2; i <= N; i++) {
		if (X[i] == 0) {
			for (int j = i; j <= N; j += i) {
				X[j] = 1;
			}

			int a = i;
			while (a <= N) {
				res.push_back(a);
				a *= i;
			}
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}
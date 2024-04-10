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
	int N, a, b;
	cin >> N >> a >> b;
	vector<int> A;
	A.push_back(a);
	A.push_back(a);
	A.push_back(a);
	A.push_back(a);
	A.push_back(b);
	A.push_back(b);
	sort(A.begin(), A.end());
	int res = 100000;
	int k = 0;
	int tres;
	do {
		k = 0;
		tres = 1;
		for (int i = 0; i < A.size(); i++) {
			k += A[i];
			if (k > N) {
				k = A[i];
				tres++;
			}
		}
		res = min(res, tres);
	} while (next_permutation(A.begin(), A.end()));

	cout << res << endl;
}
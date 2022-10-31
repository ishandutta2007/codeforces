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
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(M);
	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int cur = K;
	int pos = 0;
	while (true) {
		int ne = upper_bound(A.begin(), A.end(), cur) - A.begin();
		if (pos == ne) {
			if (pos == M)break;

			cur += K * ((A[pos] - cur + K - 1) / K);
			continue;
		}
		//cerr << ne - pos << endl;
		cur += ne - pos;
		pos = ne;
		res++;
	}

	cout << res << endl;
}
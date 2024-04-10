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
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	int X;
	cin >> X;
	vector<int> mn(N + 1, (int)1 << 60);
	mn[0] = 0;
	for (int i = 0; i < N; i++) {
		int sm = 0;
		for (int j = 0; j + i < N; j++) {
			sm += A[j + i];
			mn[j + 1] = min(mn[j + 1], sm);
		}
	}
	int res = -1;
	for (int i = 0; i < M; i++) {
		int sm = 0;
		for (int j = 0; j + i < M; j++) {
			sm += B[j + i];
			int t = upper_bound(mn.begin(), mn.end(), X / sm) - mn.begin();
			t = min(t + 3, N);
			while (mn[t] * sm > X) {
				t--;
			}
			//cerr << i << " " << j << " " << " " << t*(j + 1) << endl;
			res = max(res, t*(j + 1));
		}
	}
	cout << res << endl;
}
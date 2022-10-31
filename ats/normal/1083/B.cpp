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
	int N, K;
	cin >> N >> K;
	string S, T;
	cin >> S >> T;

	if (K == 1) {
		cout << N << endl;
		return 0;
	}
	int cur = 0;
	int res = 0;
	while (cur < N) {
		if (S[cur] != T[cur])break;
		cur++;
	}
	res = cur;
	res += (N - cur) * 2;
	K -= 2;


	cur++;
	vector<int> d(N + 1, 0);
	vector<int> p(N + 1, 0);
	for (int i = cur; i < N; i++) {
		if (S[i] == 'a') {
			d[i]++;
		}

		if (T[i] == 'b') {
			d[i]++;
		}
	}
	
	for (int i = 0; i < N; i++) {
		d[i] += p[i];
		p[i + 1] += p[i];
		int mn = min(d[i], K);

		K -= mn;
		d[i] -= mn;
		res += mn*(N - i);
		p[i + 1] += mn;
		if (K == 0)break;
	}
	cout << res << endl;
}
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
	vector<pair<int, int> > A(N);
	
	vector<int>X(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.rbegin(), A.rend());
	int sum = 0;
	for (int i = 0; i < M*K; i++) {
		X[A[i].second] = 1;
		sum += A[i].first;
	}
	vector<int> res(K);
	int c = 0;
	int cur = 0;
	for (int i = 0; i < N; i++) {
		if (X[i] == 1) {
			c++;
			if (c == M) {
				res[cur] = i + 1;
				cur++;
				c = 0;
			}
		}
	}
	cout << sum << endl;
	for (int i = 0; i < K - 1; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;

}
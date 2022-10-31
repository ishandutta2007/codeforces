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

	vector<pair<int, int> > A(N);
	vector<pair<int, int> > B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i].first >> B[i].second;
	}
	pair<int, int> mnA = A[0];
	pair<int, int> mnB = B[0];
	mnB.first = -mnB.first;
	mnB.second = -mnB.second;
	for (int i = 0; i < N; i++) {
		B[i].first = -B[i].first;
		B[i].second = -B[i].second;

		mnA = min(mnA, A[i]);
		mnB = min(mnB, B[i]);
	}
	cout << mnA.first - mnB.first << " " << mnA.second - mnB.second << endl;
}
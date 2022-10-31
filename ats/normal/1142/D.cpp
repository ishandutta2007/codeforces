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
int cnt[11];
int ncnt[11];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int> A;
	int N;
	{
		string S;
		cin >> S;
		N = S.size();
		A.resize(N);
		for (int i = 0; i < N; i++) {
			A[i] = S[i] - '0';
		}
	}
	int res = 0;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 11; j++) {
			ncnt[j] = 0;
		}
		for (int j = A[i] + 1; j < 11; j++) {
			int nj = ((j * (j - 1) / 2) + A[i] + 10) % 11;
			ncnt[nj] += cnt[j];
		}
		swap(cnt, ncnt);
		if (A[i] != 0) {
			cnt[A[i]]++;
		}
		for (int j = 0; j < 11; j++) {
			res += cnt[j];
		}
	}

	cout << res << endl;

}
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
	string S;
	cin >> S;
	int N = S.size();
	vector<int> A(N + 1, 0);
	vector<int> B(N + 1, 0);
	vector<int> num(N + 1, 0);
	num[0] = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') {
			A[i + 1] = 1;
			B[i + 1] = 1;
		}
		else if (S[i] == ')') {
			A[i + 1] = -1;
			B[i + 1] = -1;
		}
		else {
			num[i + 1] = 1;
			B[i + 1] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		num[i] += num[i - 1];
		A[i] += A[i - 1];
		B[i] += B[i - 1];
	}
	int mnb = 0;
	int res = 0;
	int mn, mx;
	for (int i = 0; i < N; i++) {
		mn = 0;
		mx = 0;
		for (int j = 0; j + i < N; j++) {
			if (S[i + j] == '(') {
				mn++;
				mx++;
			}else if (S[i + j] == ')') {
				mn--;
				mx--;
			}
			else {
				mn--;
				mx++;
			}
			if (mx < 0)break;
			if (mn < 0)mn = 1;
			if (mn == 0)res++;
		}
	}
	cout << res << endl;
}
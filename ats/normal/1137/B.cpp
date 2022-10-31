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
	int num[2];
	num[0] = num[1] = 0;
	int sum = S.size();
	for (int i = 0; i < S.size(); i++) {
		num[S[i] - '0']++;
	}

	string T;
	cin >> T;

	int N = T.size();
	
	vector<int> A(N + 1, -1);
	
	A[0] = -1;
	int j = -1;
	for (int i = 0; i < T.size(); i++) {
		while (j >= 0 && T[i] != T[j]) j = A[j];
		j++;
		A[i + 1] = j;
	}
	
	int k = A.back();

	//cerr << k << endl;


	int cur = 0;
	string res;
	while (true) {
		if (num[0] == 0) {
			while (res.size() < sum)res.push_back('1');
			break;
		}
		else if (num[1] == 0) {
			while (res.size() < sum)res.push_back('0');
			break;
		}
		res.push_back(T[cur]);
		num[T[cur] - '0']--;
		cur++;
		if (cur == N) {
			cur = k;
		}

	}
	cout << res << endl;

}
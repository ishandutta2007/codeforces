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
	N--;
	string X;
	string Y;
	cin >> X >> Y;
	string S;


	for (int i = N - 1; i >= 0; i--) {
		if (X[i] == 'N')S.push_back('S');
		else if (X[i] == 'S')S.push_back('N');
		else if (X[i] == 'W')S.push_back('E');
		else if (X[i] == 'E')S.push_back('W');
	}
	for (int i = 0; i < N; i++) {
		S.push_back(Y[i]);
	}
	vector<int> A(S.size(), 0);
	{
		A[0] = S.size();
		int i = 1, j = 0;
		while (i < S.size()) {
			while (i + j < S.size() && S[j] == S[i + j]) ++j;
			A[i] = j;
			if (j == 0) { ++i; continue; }
			int k = 1;
			while (i + k < S.size() && k + A[k] < j) A[i + k] = A[k], ++k;
			i += k; j -= k;
		}
	}
	string res = "YES";
	for (int i = N; i < 2 * N; i++) {
		if (A[i] == 2 * N - i)res = "NO";
	}


	cout << res << endl;
}
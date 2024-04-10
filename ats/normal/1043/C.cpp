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
	string S;
	cin >> S;
	N = S.size();
	vector<int> res(N, 0);
	S.push_back('b');
	for (int i = 0; i < N; i++) {
		if (S[i] != S[i + 1]) {
			res[i] = 1;
		}
	}
	/*for (int i = 0; i < N; i++) {
		if (res[i] == 1) {
			reverse(S.begin(), S.begin() + (i + 1));
		}
	}
	cerr << S << endl;*/
	//cout << N << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}
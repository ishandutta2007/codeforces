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
	string S, T;
	int c = 0;
	while (c < N) {
		c += 9;
		S.push_back('9');
	}
	T = S;
	c = 0;
	while (c < N) {
		c += 9;
		T.push_back('0');
	}
	T.back() = '1';
	//reverse(T.begin(), T.end());
	cout << S << endl;
	cout << T << endl;
}
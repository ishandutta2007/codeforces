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
	vector<int> A(N);
	int res = 0;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a; a--;
		A[a] = i;
	}
	int c = 1;
	for (int i = 1; i < N; i++) {
		if (A[i - 1] < A[i]) {
			c++;
		}
		else {
			res = max(res, c);
			c = 1;
		}
	}
	res = max(res, c);



	cout << N - res  << endl;
}
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
	
	vector<int> X;
	int i = 1;
	while (N > 0) {
		if (N % 2 == 1) {
			X.push_back(i);
		}
		i++;
		N /= 2;
	}
	reverse(X.begin(), X.end());
	for (int i = 0; i < X.size(); i++) {
		if (i > 0)cout << " ";
		cout << X[i];
	}
	cout << endl;
}
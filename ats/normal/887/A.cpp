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
	vector<int> A(N);
	int mx = -1;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			mx = max(mx, (int)0);
		}
		else {
			if (mx != -1) {
				mx++;
			}
		}
	}
	if (mx >= 6) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	
}
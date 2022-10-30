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
	int N, D;
	cin >> N >> D;
	string S;
	cin >> S;
	int k = 0;
	int res = 0;
	while (k < N - 1) {
		for (int i = min(N - 1,k + D); i > k; i--) {
			if (S[i] == '1') {
				k = i;
				res++;
				break;
			}
			if (i == k + 1) {
				res = -1;
				break;
			}
		}
		if (res == -1)break;
	}
	cout << res << endl;
}
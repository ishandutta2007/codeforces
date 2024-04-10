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
	string S;
	cin >> S;
	int res = 0;
	int a[26];
	int k = 0;
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
	}
	int cnt = 0;
	int st = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] >= 'A' && S[i] <= 'Z') {
			for (int j = 0; j < 26; j++) {
				a[j] = 0;
				k = 0;
				cnt = 0;
				st = i + 1;
			}
		}
		else {
			a[(int)(S[i] - 'a')]++;
			if (a[(int)(S[i] - 'a')] == 1) {
				k++;
			}
			res = max(res, k);
		}
	}
	cout << res << endl;
}
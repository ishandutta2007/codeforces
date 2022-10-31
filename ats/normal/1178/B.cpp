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
	int tot = 0;
	for (int i = 1; i < N; i++) {
		if (S[i] == S[i - 1] && S[i] == 'v') {
			tot++;
		}
	}
	int res = 0;
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		if (S[i] == 'o') {
			res += cnt * (tot - cnt);
		}else if (S[i] == S[i - 1] && S[i] == 'v') {
			cnt++;
		}
	}



	cout << res << endl;
}
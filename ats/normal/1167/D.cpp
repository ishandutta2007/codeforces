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
	int a = 0;
	string res;
	int mx = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') {
			a++;
			res.push_back((a % 2) + '0');
			mx = max(mx, a);
		}
		else {
			res.push_back((a % 2) + '0');
			a--;
		}
	}
	cout << res << endl;
}
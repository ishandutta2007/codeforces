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
	vector<string> ss(N);
	int res = 0;
	vector<int>lz(10, 0);
	vector<pair<int, int> > sm(10);
	for (int i = 0; i < 10; i++) {
		sm[i].second = i;
		sm[i].first = 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> ss[i];
		lz[ss[i][0] - 'a'] = 1;
	}
	int a;
	for (int i = 0; i < N; i++) {
		a = 1;
		for (int j = ss[i].size() - 1; j >= 0; j--) {
			sm[ss[i][j] - 'a'].first += a;
			a *= 10;
		}
	}
	sort(sm.begin(), sm.end());
	int n = 1;
	int zero = 1;
	for (int i = 9; i >= 0; i--) {
		if (lz[sm[i].second] == 1) {
			res += sm[i].first * n;
			n++;
		}
		else {
			if (zero == 1) {
				zero = 0;
			}
			else {
				res += sm[i].first * n;
				n++;
			}
		}
	}

	cout << res << endl;
}
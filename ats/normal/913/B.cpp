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
	vector<vector<int> >ed(N);
	int res = 0;
	int a;
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		a--;
		ed[a].push_back(i + 1);
	}
	bool f = true;
	int c;
	for (int i = 0; i < N; i++) {
		if (ed[i].size() > 0) {
			c = 0;
			for (int j = 0; j < ed[i].size(); j++) {
				if ((int)ed[ed[i][j]].size() == 0) {
					c++;
				}
			}
			if (c < 3) {
				f = false;
				break;
			}
		}
	}
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
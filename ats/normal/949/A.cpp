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
	string  S;
	cin >> S;
	int c0 = 0;
	int c1 = 0;
	int N = S.size();
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			c1++;
		}
		else {
			c0++;
		}
	}
	if (c0 > c1) {
		res = c0 - c1;
		vector<vector<int> > v(res);
		set<int> next0;
		set<int> next1;
		for (int i = 0; i < res; i++) {
			next0.insert(i);
		}
		for (int i = 0; i < N; i++) {
			if (S[i] == '1') {
				if ((int)next1.size() > 0) {
					int k = (*next1.begin());
					v[k].push_back(i + 1);
					next1.erase(k);
					next0.insert(k);
				}
				else {
					cout << -1 << endl;
					return 0;
				}
			}
			else {
				if ((int)next0.size() > 0) {
					int k = (*next0.begin());
					v[k].push_back(i + 1);
					next0.erase(k);
					next1.insert(k);
				}
				else {
					cout << -1 << endl;
					return 0;
				}
			}
		}

		cout << res << endl;
		for (int i = 0; i < res; i++) {
			cout << v[i].size();
			for (int j = 0; j < v[i].size(); j++) {
				cout << " " << v[i][j];
			}
			cout << endl;
		}

	}
	else {
		cout << -1 << endl;
		return 0;
	}
	
}
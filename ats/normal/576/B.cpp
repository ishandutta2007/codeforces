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
	for (int i = 0; i < N; i++) {
		cin >> A[i]; A[i]--;
	}

	if (N == 1) {
		cout << "YES" << endl;
		cout << endl;
		return 0;
	}
	vector<int> X(N, 0);
	vector<pair<int, int> > vp;
	for (int i = 0; i < N; i++) {
		if (X[i] == 0) {
			int a = i;
			vector<int> t;
			while (true) {
				t.push_back(a);
				X[a] = 1;
				a = A[a];
				if (a == i)break;
			}
			if ((int)t.size() == 1) {
				for (int j = 0; j < N; j++) {
					if (j != t[0]) {
						vp.emplace_back(t[0], j);
					}
				}
				break;
			}
		}
	}

	if (vp.size()) {
		cout << "YES" << endl;
		for (int i = 0; i < vp.size(); i++) {
			cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
		}
	}
	else {
		X.clear();
		X.resize(N, 0);
		int C[2];
		C[0] = -1;
		for (int i = 0; i < N; i++) {
			if (X[i] == 0) {
				int a = i;
				vector<int> t;
				while (true) {
					t.push_back(a);
					X[a] = 1;
					a = A[a];
					if (a == i)break;
				}
				
					if ((int)t.size() == 2) {
						C[0] = t[0];
						C[1] = t[1];
						break;
					}
				
			}
		}
		if (C[0] != -1) {
			X.clear();
			X.resize(N, 0);
			vp.emplace_back(C[0], C[1]);
			for (int i = 0; i < N; i++) {
				if (X[i] == 0) {
					int a = i;
					vector<int> t;
					while (true) {
						t.push_back(a);
						X[a] = 1;
						a = A[a];
						if (a == i)break;
					}
					if ((int)t.size() % 2 == 1) {
						vp.clear();
						break;
					}
					if (C[0] != t[0]) {
						for (int j = 0; j < t.size(); j++) {
							vp.emplace_back(C[j % 2], t[j]);
						}
					}
				}
			}
		}

		if (vp.size()) {
			cout << "YES" << endl;
			for (int i = 0; i < vp.size(); i++) {
				cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}

}
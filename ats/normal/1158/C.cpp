#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int solve() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if(A[i] > 0)A[i]--;
	}
	vector<vector<int> > v(N + 1);
	vector<int> order;
	vector<int> tmp;
	for (int i = 0; i <= N; i++) {
		while (v[i].size() > 0) {
			int k = v[i].back();

			while (tmp.size() > 0 && A[tmp.back()] == -1) {
				order.push_back(tmp.back());
				//A[tmp.back()] = i;
				tmp.pop_back();
			}

			if (tmp.size() == 0 || A[tmp.back()] != i) {
				cout << -1 << endl;
				return 0;
			}
			order.push_back(tmp.back());
			tmp.pop_back();
			v[i].pop_back();
		}
		if (i < N) {
			tmp.push_back(i);
			if (A[i] != -1)v[A[i]].push_back(i);
		}
	}
	while (tmp.size() > 0) {
		order.push_back(tmp.back());
		tmp.pop_back();
	}

	//reverse(order.begin(), order.end());
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		//cerr << order[i] << " ";
		res[order[i]] = i + 1;
	}

	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
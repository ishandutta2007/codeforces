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
	vector<pair<int,int> > A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].second;
		A[i].first = -1;
	}
	int Q;
	cin >> Q;
	int t;
	vector<pair<int, int> > X;
	for (int i = 0; i < Q; i++) {
		cin >> t;
		if (t == 1) {
			int p, x;
			cin >> p >> x;
			p--;
			A[p].first = i;
			A[p].second = x;
		}
		else {
			int x;
			cin >> x;
			pair<int, int> p(i, x);
			while (X.size() > 0 && X.back().second < p.second) {
				X.pop_back();
			}
			X.push_back(p);
		}
	}
	X.emplace_back(Q, -1);
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		res[i] = max(A[i].second, (*lower_bound(X.begin(), X.end(), A[i])).second);
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}
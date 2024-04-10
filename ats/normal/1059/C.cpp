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
int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > X(N + 1);
	vector<int> cnt(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			X[j].push_back(i);
			cnt[i]++;
		}
	}
	vector<int> V(N);
	for (int i = 0; i < N; i++) {
		V[i] = i + 1;
	}
	vector<int> res;
	int cur = 1;
	while ((int)V.size() > 1) {
		pair<int, int> mx;
		mx.first = -1;
		pair<int, int> t;
		int k = -1;
		for (int i = 0; i < V.size(); i++) {
			if (cnt[V[i]] != V.size()) {
				t = make_pair(cnt[V[i]], cur * V[i] / gcd(cur, V[i]));
				if (mx < t) {
					mx = t;
					k = V[i];
				}
			}
		}
		for (int i = V.size() - 1; i >= 0; i--) {
			if (V[i] % k != 0) {
				for (auto j : X[V[i]]) {
					cnt[j]--;
				}
				swap(V[i], V.back());
				V.pop_back();	res.push_back(cur);
			}
		}
		cur = mx.second;
	}
	res.push_back(V[0]);
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}
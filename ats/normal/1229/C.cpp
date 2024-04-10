#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
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
	int N, M;
	cin >> N >> M;
	int res = 0;
	vector<vector<int> > B(N);
	vector<int> deg(N);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		deg[a]++;
		deg[b]++;
		if (a > b)swap(a, b);
		B[a].push_back(b);
	}

	for (int i = 0; i < N; i++) {
		res += (deg[i] - B[i].size()) * B[i].size();
	}
	cout << res << '\n';

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> a;
		a--;
		res -= (deg[a] - B[a].size()) * B[a].size();
		for (int j : B[a]) {
			res += (int)deg[j] - B[j].size() - B[j].size() - 1;
			B[j].push_back(a);
		}
		B[a].clear();
		cout << res << '\n';
	}

	cout << flush;
	return 0;
}
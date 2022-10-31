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
	int N, S;
	cin >> N >> S;
	vector<vector<int> > g(N);
	int res = 0;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int l = 0;
	for (int i = 0; i < N; i++) {
		if (g[i].size() == 1) {
			l++;
		}
	}

	cout << fixed << setprecision(15) << ((2.0*S) / l) << endl;
}
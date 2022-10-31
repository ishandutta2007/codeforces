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
	vector<vector<int> > g(N);
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		B[A[i]] = i;
	}
	queue<int> qu;
	qu.push(0);
	vector<int> V(N, 0);
	V[0] = 1;
	vector<pair<int, int> > tmp;
	int cur = 0;
	string res = "Yes";
	while (!qu.empty()) {
		a = qu.front(); qu.pop();
		//cerr << a << endl;
		if (a != A[cur]) {
			res = "No";
			break;
		}
		cur++;
		tmp.clear();
		for (int i = 0; i < g[a].size(); i++) {
			if (V[g[a][i]] == 0) {
				tmp.emplace_back(B[g[a][i]], g[a][i]);
				V[g[a][i]] = 1;
			}
		}
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < tmp.size(); i++) {
			qu.push(tmp[i].second);
		}
	}
	cout << res << endl;
}
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
vector<vector<int> >ed;
vector<vector<char> >ec;
vector<map<int, int> > vm;
vector<vector<vector<int> > > dp;
int rec(int i, int j, int k) {
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}
	dp[i][j][k] = 0;
	for (int a = 0; a < ed[i].size(); a++) {
		if (ec[i][a] - 'a' >= k) {
			if (rec(j, ed[i][a], ec[i][a] - 'a') == 0) {
				dp[i][j][k] = 1;
			}
		}
	}
	return dp[i][j][k];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int res = 0;
	int a, b;
	char c;
	ed.resize(N);
	ec.resize(N);
	vm.resize(N);
	vector<int> A(N, 0);
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		A[a] = 1;
		ed[a].push_back(b);
		ec[a].push_back(c);
	}
	dp.resize(N, vector<vector<int> >(N, vector <int>(26, -1)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (dp[i][j][0] == -1) {
				rec(i, j, 0);
			}

		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j][0] == 1) {
				cout << "A";
			}
			else {
				cout << "B";
			}
		}
		cout << endl;
	}
}
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
vector<vector<int> > ed;
vector<int> num;
vector<vector<int> > d;
vector<vector<int> > dp;
vector<int> lf;
int nn;
int N;
int bs(int a, int b) {
	int u = 1000000000;
	int dn = 0;
	int t;
	int m;
	bool f;
	while (u - dn > 1) {
		m = (u + dn) / 2;
		t = 0;

		for (int i = 0; i < N; i++) {

			if (lf[i] == 1) {
				if (i != a) {
					f = true;
					for (int j = 1; j <= b; j++) {
						if (d[a][i] + dp[i][b - j] < m) {
							t += j - 1;
							f = false;
							break;
						}
					}
					if (f) {
						t += b;
					}
				}
			}
		}

		if (t >= b) {
			dn = m;
		}
		else {
			u = m;
		}
	}

	return dn;
}
int bs2(int a, int b,int M) {
	int u = 1000000000;
	int dn = 0;
	int t;
	int m;
	bool f;
	while (u - dn > 1) {
		m = (u + dn) / 2;
		t = 0;

		for (int i = 0; i < N; i++) {

			if (lf[i] == 1) {
				if (i != a) {
					f = true;
					for (int j = 1; j <= b; j++) {
						if (d[a][i] + dp[i][M - j] < m) {
							t += j - 1;
							f = false;
							break;
						}
					}
					if (f) {
						t += b;
					}
				}
			}
		}

		if (t >= b) {
			dn = m;
		}
		else {
			u = m;
		}
	}

	return dn;
}
void dfs(int a, int from) {
	nn += num[a];
	if ((int)ed[a].size() == 1) {
		lf[a] = 1;
	}
	for (int i = 0; i < ed[a].size(); i++) {
		if (ed[a][i] != from) {
			dfs(ed[a][i], a);
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	ed.resize(N);
	num.resize(N, 0);
	lf.resize(N, 0);
	int st;
	d.resize(N, vector<int>(N, 1000000000));
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		d[a][b] = c;
		d[b][a] = c;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	cin >> st;
	st--;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a;
		a--;
		num[a]++;
	}
	dp.resize(N, vector<int>(M + 1, 0));
	for (int i = 0; i < N; i++) {
		if ((int)ed[i].size() == 1) {
			lf[i] = 1;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		d[i][i] = 0;
	}
	for (int i = 0; i < N; i++) {
		dp[i][0] = 0;
	}
	for (int j = 1; j <= M; j++) {
		for (int i = 0; i < N; i++) {
			if (ed[i].size() == 1) {
				dp[i][j] = bs(i, j);
			}
		}
	}
	int res = 100000000;
	int pp;
	for (int i = 0; i < ed[st].size(); i++) {
		for (int j = 0; j < N; j++) {
			lf[j] = 0;
		}
		nn = 0;
		dfs(ed[st][i], st);
		if (nn > 0) {
			res = min(res, bs2(st, nn, M));
		}
	}
	cout << res << endl;
}
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
	vector<vector<int> > A(N);
	vector<int> sum(N, 0);
	map<int, pair<int, int> > mp;
	vector<vector<pair<int, int> > > vp(N);
	vector<vector<int> > V(N);
	int tot = 0;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		A[i].resize(K);
		vp[i].resize(K);
		V[i].resize(K, 0);
		for (int j = 0; j < K; j++) {
			cin >> A[i][j];
			mp[A[i][j]] = make_pair(i, j);
			sum[i] += A[i][j];
		}
		tot += sum[i];
	}

	if (abs(tot) % N != 0) {
		cout << "No" << endl;
		return 0;
	}
	int ave = tot / N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i].size(); j++) {
			auto t = mp.find(-sum[i] + A[i][j] + ave);
			if (t != mp.end()) {
				vp[i][j] = (*t).second;
			}
			else {
				vp[i][j].first = -1;
			}
		}
	}

	vector<vector<pair<int, int> > >cs;
	map<int, vector<pair<int, int> > >mpc;

	vector<vector<int> > C(N);
	for (int i = 0; i < N; i++) {
		C[i].resize(A[i].size(), 0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i].size(); j++) {
			if (C[i][j] == 0) {
				pair<int, int> cur(i, j);
				bool ok = true;
				vector<int> S(N, 0);
				vector<pair<int, int> > ans;
				for (int k = 0; k < N; k++) {
					pair<int, int> ne = vp[cur.first][cur.second];
					if (ne.first == -1) {
						ok = false;
						break;
					}
					cur = ne;
					S[cur.first]++;
					if (S[cur.first] == 2) {
						ok = false;
						break;
					}
					ans.push_back(cur);
					if (cur.first == i && cur.second == j)break;
				}
				if (ok) {
					if (ok) {
						int bit = 0;
						for (int k = 0; k < ans.size(); k++) {
							C[ans[k].first][ans[k].second] = 1;
							bit |= (1 << ans[k].first);
						}
						mpc[bit] = ans;
						//cs.push_back(ans);

					}
				}

			}
		}
	}
	vector<int> bs;
	for (auto &m : mpc) {
		cs.push_back(m.second);
		bs.push_back(m.first);
	}
	vector<int> use;
	int ai = (1 << N) - 1;
	vector<int> dp(1 << N);
	vector<pair<int, int> > from(1 << N);
	dp[0] = 1;

	for (int i = 0; i < cs.size(); i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (dp[j] == 1) {
				if ((j & bs[i]) == 0) {
					if (dp[j | bs[i]] == 0) {
						dp[j | bs[i]] = 1;
						from[j | bs[i]] = make_pair(j, i);
					}
				}
			}
		}
	}


	if (dp[(1 << N) - 1] == 1) {
		int cur = (1 << N) - 1;
		while (true){
			use.push_back(from[cur].second);
			cur = from[cur].first;
			if (cur == 0)break;
		}

		cout << "Yes" << endl;
		vector<pair<int, int> > res(N);
		for (int i : use) {
			vector<pair<int, int> > &ans = cs[i];
			for (int k = 0; k < ans.size(); k++) {

				int b = k - 1;
				if (b == -1)b = (int)ans.size() - 1;
				res[ans[k].first].first = A[ans[k].first][ans[k].second];
				res[ans[k].first].second = ans[b].first + 1;
			}
		}
		for (int k = 0; k < N; k++) {
			cout << res[k].first << " " << res[k].second << endl;
		}

		return 0;

	}




	cout << "No" << endl;
}
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
	int M, N;
	cin >> M >> N;
	vector<int> A(N);
	vector<int> B(N);
	int res = 0;
	vector<pair<int, pair<int,int> > > vp;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		vp.emplace_back(A[i], make_pair(0, i));
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		vp.emplace_back(B[i], make_pair(1, i));
	}
	sort(vp.begin(), vp.end());

	for (int i = 0; i < 2 * N; i++) {
		vp.push_back(vp[i]);
		vp.back().first += M;
	}

	vector<int> rs(4 * N + 5, -1);
	vector<int> cur(4 * N + 5, -1);
	vector<int> sum(4 * N + 5, 0);
	vector<vector<pair<int,int> > > idx(4 * N + 5);
	vector<int> al(4 * N + 5, 0);
	int s = 2 * N + 2;

	for (int i = 0; i < vp.size(); i++) {
		int pos = vp[i].first;
		if (vp[i].second.first == 1) {
			s--;
		}
		if (rs[s] == -1) {
			rs[s] = pos;
		}
		
		if (pos <= rs[s] + M) {
			idx[s].push_back(vp[i].second);
			if (cur[s] == -1) {
				cur[s] = pos;
			}
			else {
				sum[s] += pos - cur[s];
				cur[s] = -1;
			}
		}
		if (vp[i].second.first == 0) {
			s++;
		}
	}
	int INF = (int)1 << 60;
	res = INF;
	int ans = 0;
	for (int i = 0; i < sum.size(); i++) {
		ans += sum[i];
	}
	//cerr << ans << endl;
	int mni = -1;
	res = ans;
	for (int i = 0; i < vp.size(); i++) {
		int pos = vp[i].first;
		if (vp[i].second.first == 1) {
			s--;
		}
		ans -= sum[s];
		sum[s] = M - sum[s];
		ans += sum[s];
		if (res > ans) {
			mni = i;
			res = ans;
		}
		if (vp[i].second.first == 0) {
			s++;
		}
	}
	//cerr << "mni = " << mni << endl;
	for (int i = 0; i < vp.size(); i++) {
		if (i > mni)break;
		int pos = vp[i].first;
		if (vp[i].second.first == 1) {
			s--;
		}
		al[s] ^= 1;
		if (vp[i].second.first == 0) {
			s++;
		}
	}

	vector<int> X(N);

	for (int i = 0; i < idx.size(); i++) {
		for (int j = al[i]; j + 1 < idx[i].size(); j += 2) {
			if (idx[i][j].first == 0) {
				X[idx[i][j].second] = idx[i][j + 1].second;
			}
			else {
				X[idx[i][j + 1].second] = idx[i][j].second;
			}
		}
	}
	cout << res << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << X[i] + 1;
	}
	cout << endl;
}
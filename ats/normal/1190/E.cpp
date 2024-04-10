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
double PI2 = 2 * acos(-1);
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> X(N), Y(N);
	vector<double> len(N);
	vector<double> invlen(N);
	vector<double> rad(N);
	int res = 0;
	double mn = 1e9;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		len[i] = hypot(X[i], Y[i]);
		invlen[i] = 1 / len[i];
		rad[i] = atan2(X[i], Y[i]);
		mn = min(mn, len[i]);

	}

	double u = mn;
	double d = 0;
	int B = 17;
	int N2 = 2 * N;
	vector<vector<int> > ne(N2, vector<int>(B));
	while (u - d > 1e-7) {
		double m = (u + d)*0.5;

		vector<pair<double, double> > vp(N2);
		for (int i = 0; i < N; i++) {
			double d = acos(min(1.0, m * invlen[i]));
			vp[i].first = rad[i] + d;
			vp[i].second = rad[i] - d;
			while (vp[i].first < 0) {
				vp[i].first += PI2;
				vp[i].second += PI2;
			}
			while (vp[i].first > PI2) {
				vp[i].first -= PI2;
				vp[i].second -= PI2;
			}
			vp[i + N].first = vp[i].first + PI2;
			vp[i + N].second = vp[i].second + PI2;
		}
		sort(vp.begin(), vp.end());
		int cnt = 0;
		queue<int> qu;

		for (int i = 0; i < N2; i++) {
			ne[i][0] = N2;
		}
		for (int i = 0; i < N2; i++) {
			while (qu.size() > 0) {
				double R = vp[qu.front()].first;
				if (R < vp[i].second) {
					ne[qu.front()][0] = i;
					qu.pop();
				}
				else {
					break;
				}
			}
			qu.push(i);
		}
		for (int i = 1; i < B; i++) {
			for (int j = 0; j < N2; j++) {
				if (ne[j][i - 1] < N2) {
					ne[j][i] = ne[ne[j][i - 1]][i - 1];
				}
				else {
					ne[j][i] = N2;
				}
			}
		}

		cnt = N;
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			int cur = i;
			for (int j = B - 1; j >= 0; j--) {
				if (ne[cur][j] < i + N) {
					cur = ne[cur][j];
					tmp += (1 << j);
				}
			}
			cnt = min(cnt, tmp + 1);
		}
		//cerr << m << " " << cnt << endl;

		if (cnt > M) {
			u = m;
		}
		else {
			d = m;
		}
	}


	cout << fixed << setprecision(15) << (u + d) * 0.5 << endl;
}
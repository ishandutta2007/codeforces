#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
int N, M, K;
int INF = (int)1 << 60;
void dist(vector<vector<int> > &g, vector<int> &D, int s) {
	D.resize(N, INF);
	queue<int> qu;
	qu.push(s);
	D[s] = 0;
	while (qu.size()) {
		int a = qu.front();
		qu.pop();
		for (const int &i : g[a]) {
			if (D[i] > D[a] + 1) {
				D[i] = D[a] + 1;
				qu.push(i);
			}
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	vector<int> S(N, 0);
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		a--;
		S[a] = 1;
	}
	vector<vector<int> > g(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> A;
	vector<int> B;
	dist(g, A, 0);
	dist(g, B, N - 1);
	int res = A[N - 1];
	vector<pair<int, int> > vp;
	for (int i = 0; i < N; i++) {
		if (S[i]) {
			vp.emplace_back(A[i] - B[i], B[i]);
			//cerr << A[i] <<" " << B[i]<<endl;
		}
	}
	sort(vp.begin(), vp.end());
	vector<int> mxR(K + 1);
	mxR[K] = -INF;
	for (int i = K - 1; i >= 0; i--) {
		mxR[i] = max(mxR[i + 1], vp[i].second);
	}
	vector<int> mxL(K + 1);
	mxL[0] = -INF;
	for (int i = 0; i < K; i++) {
		mxL[i + 1] = max(mxL[i], vp[i].first + vp[i].second);
	}
	int mx = 0;
	for (int i = 0; i < vp.size(); i++) {
		//cerr << i << " " << vp[i].first + vp[i].second + mxR[i + 1] << endl;
		//cerr << i << " " << vp[i].second + mxL[i] << endl;
		mx = max(mx, vp[i].first + vp[i].second + mxR[i + 1]);
		mx = max(mx, vp[i].second + mxL[i]);
	}
	//cerr << mx << endl;
	res = min(res, mx + 1);
	cout << res << endl;
}
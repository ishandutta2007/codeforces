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
struct Query {
	int a; 
	int b;
	int idx;
	int ans;
	bool operator<(const Query &right) const {
		return a < right.a;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	vector<Query> qs(Q);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < Q; i++) {
		cin >> qs[i].a >> qs[i].b; qs[i].a--;
		qs[i].idx = i;
	}
	sort(qs.begin(), qs.end());

	int INF = (int)1 << 50;
	
	vector<int>  X(N + 1, INF);
	vector<int>  Y(N + 1, INF);

	vector<int> T(N);
	
	vector<pair<int, int> > vp(N);
	for (int i = N - 1; i >= 0; i--) {
		int t = lower_bound(Y.begin(), Y.end(), -A[i]) - Y.begin();
		vp[i] = make_pair(t, Y[t]);
		Y[t] = -A[i];
	}

	int qi = 0;
	for (int i = 0; i < N; i++) {

		Y[vp[i].first] = vp[i].second;
	/*	for (int j = 0; j < Y.size(); j++) {
			cerr << Y[j] << " ";
		}
		cerr << endl;*/
		while (qi < Q && qs[qi].a <= i) {
			if (qs[qi].a == i) {
				qs[qi].ans = 0;
				qs[qi].ans += lower_bound(X.begin(), X.end(), qs[qi].b) - X.begin();
				qs[qi].ans += lower_bound(Y.begin(), Y.end(), -qs[qi].b) - Y.begin();
				qs[qi].ans++;
			}
			qi++;
		}



		auto t = lower_bound(X.begin(), X.end(), A[i]);
		T[i] = t - X.begin();
		*t = A[i];
	}








	int lis = lower_bound(X.begin(), X.end(), INF) - X.begin();
	vector<vector<int> > use(lis + 1);
	vector<int> mx(lis + 1);
	mx[lis] = INF;

	for (int i = N - 1; i >= 0; i--) {
		if (A[i] < mx[T[i] + 1]) {
			use[T[i]].push_back(i);
			mx[T[i]] = A[i];
		}
	}
	vector<int> must(N, 0);
	vector<int> can(N, 0);
	for (int i = 0; i < lis; i++) {
		if (use[i].size() == 1) {
			must[use[i][0]] = 1;
		}
		else if ((int)use[i].size() >= 2) {
			for (int k : use[i]) {
				can[k] = 1;
			}
		}
	}

	/*cerr << lis << endl;
	for (int i = 0; i < 4; i++) {
		cerr << must[i] << " ";
	}*/
	for (int i = 0; i < Q; i++) {
		if (must[qs[i].a] == 0) {
			qs[i].ans = max(qs[i].ans, lis);
		}
		else {
			qs[i].ans = max(qs[i].ans, lis - 1);
		}
	}

	vector<int> res(Q);
	for (int i = 0; i < Q; i++) {
		res[qs[i].idx] = qs[i].ans;
	}

	for (int i = 0; i < Q; i++) {
		cout << res[i] << endl;
	}
}
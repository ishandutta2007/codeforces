#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> A(N, 0);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		A[a] += c;
		A[b] -= c;
	}
	vector<pair<int, int> > vp1;
	vector<pair<int, int> > vp2;
	for (int i = 0; i < N; i++) {
		if (A[i] > 0) {
			vp1.emplace_back(A[i], i);
		} else if (A[i] < 0) {
			vp2.emplace_back(-A[i], i);
		}
	}
	int cur1 = 0;
	int cur2 = 0;
	vector<pair<pair<int, int>, int> > res;
	while (true) {
		while (cur1 < vp1.size() && vp1[cur1].first == 0) {
			cur1++;
		}
		while (cur2 < vp2.size() && vp2[cur2].first == 0) {
			cur2++;
		}
		if (cur1 == (int)vp1.size() && (int)cur2 == vp2.size()) {
			break;
		}
		int mn = min(vp1[cur1].first, vp2[cur2].first);
		//cerr << mn<<endl;
		res.emplace_back(make_pair(vp1[cur1].second, vp2[cur2].second), mn);
		vp1[cur1].first -= mn;
		vp2[cur2].first -= mn;
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first.first + 1 << " " << res[i].first.second + 1 << " " << res[i].second << endl;
	}
}
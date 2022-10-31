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
	int N, M;
	cin >> N >> M;
	vector<pair<int, int> > A(M);

	int l, r;
	int ll, rr;
	vector<pair<pair<int, int>, int > > X;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		if (i > 0) {
			X.emplace_back(make_pair(r - ll, l - rr), i - 1);
		}
		ll = l;
		rr = r;
	}
	set<pair<int, int> > st;
	for (int i = 0; i < M; i++) {
		cin >> A[i].first;
		A[i].second = i + 1;
		st.insert(A[i]);
	};
	sort(X.begin(), X.end());
	vector<int> res(N - 1);
	int j = 0;
	pair<int, int> t;
	t.second = -1;
	for (int i = 0; i < X.size(); i++) {
		t.first = X[i].first.second;
		st.insert(t);
		auto s = st.find(t); s++;
		if (s == st.end() || (*s).first > X[i].first.first) {
			cout << "No" << endl;
			return 0;
		}
		res[X[i].second] = (*s).second;
		st.erase(s);
		st.erase(t);
	}
	cout << "Yes" << endl;
	for (int i = 0; i < N - 1; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}
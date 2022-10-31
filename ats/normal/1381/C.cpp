#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N, X, Y;
		cin >> N >> X >> Y;
		vector<int> A(N);
		set<int> st;
		for (int i = 0; i < N + 1; i++) {
			st.insert(i);
		}
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			A[i]--;
			st.erase(A[i]);
		}
		int b = *st.begin();
		if (Y < X) {
			cout << "NO"
				 << "\n";
			continue;
		}
		vector<int> res = A;
		vector<vector<int> > pos(N + 1);
		set<pair<int, int> > cnt;
		for (int i = 0; i < N; i++) {
			pos[A[i]].push_back(i);
		}
		for (int i = 0; i < N + 1; i++) {
			cnt.emplace(pos[i].size(), i);
		}
		for (int i = 0; i < X; i++) {
			auto x = cnt.end();
			x--;
			int sz1 = (*x).first;
			int vl1 = (*x).second;
			cnt.erase(x);
			pos[vl1].pop_back();
			cnt.emplace(sz1 - 1, vl1);
		}
		bool ok = true;
		int z = 0;
		int y = X;
		int lvl1 = -1;
		int lvl2 = -1;
		int lps1;
		int lps2;
		vector<int> T;
		for (int i = 0; i < Y - X; i++) {
			auto x = cnt.end();
			x--;
			int sz1 = (*x).first;
			int vl1 = (*x).second;
			cnt.erase(x);
			x = cnt.end();
			x--;
			int sz2 = (*x).first;
			int vl2 = (*x).second;
			cnt.erase(x);
			if (sz1 > 0 && sz2 == 0) {
				if (lvl1 >= 0 && vl1 != lvl1 && vl1 != lvl2) {
					T.push_back(pos[vl1].back());
					swap(res[pos[vl1].back()], res[lps2]);
					pos[vl1].pop_back();
					y += 1;
				}
				break;
			} else if (sz2 == 0) {
				break;
			}
			lvl1 = vl1;
			lvl2 = vl2;
			lps1 = pos[vl1].back();
			lps2 = pos[vl2].back();
			T.push_back(lps1);
			T.push_back(lps2);
			swap(res[pos[vl1].back()], res[pos[vl2].back()]);
			pos[vl1].pop_back();
			pos[vl2].pop_back();
			cnt.emplace(sz1 - 1, vl1);
			cnt.emplace(sz2 - 1, vl2);
			y += 2;
		}
		if (y < Y) {
			cout << "NO"
				 << "\n";
			continue;
		}
		for (int i = 0; i < y - Y; i++) {
			res[T[i]] = b;
		}
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < pos[i].size(); j++) {
				res[pos[i][j]] = b;
			}
		}
		cout << "YES\n";
		for (int i = 0; i < N; i++) {
			if (i > 0) cout << " ";
			cout << res[i] + 1;
		}
		cout << "\n";
	}
	return 0;
}
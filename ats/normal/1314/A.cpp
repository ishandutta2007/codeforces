#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	map<int, vector<int> > A;
	vector<int> X(N);
	vector<int> Y(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> Y[i];
	}
	for (int i = 0; i < N; i++) {
		A[X[i]].push_back(Y[i]);
	}
	auto x = A.begin();
	set<pair<int, int> > st;
	int sum = 0;
	int cur = 0;
	int tmp = 0;
	for (; x != A.end() || (int)st.size() > 0;) {
		
		if ((int)st.size() == 0) {
			cur = (*x).first;
		}
		if (x != A.end()) {
			if (cur == (*x).first) {
				for (const int &a : (*x).second) {
					st.emplace(a, tmp);
					tmp++;
					sum += a;
				}
				++x;
			}
		}

		cur++;
		auto s = st.end();
		--s;
		sum -= (*s).first;
		st.erase(s);
		res += sum;
	}
	cout << res << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>

using namespace std;

const int MAXN = 100007;
int N;
int A[MAXN], comp[MAXN], col[MAXN];
bool B[MAXN];
vector<int> C, ans[3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tests; cin >> tests;
	while (tests--) {
		cin >> N;
		assert(N > 0);
		for (int i = 1; i <= N; ++i) col[i] = -1;

		if (N == 1) {
			cout << "A 1 0 0\n1\n\n" << endl;
			continue;
		}

		// part 1
		for (int i = 1; i <= N; ++i) A[i] = -1;
		while (true) {
			for (int i = 1; i <= N; ++i) B[i] = 0;
			vector<int> queries;
			for (int i = 1; i <= N; ++i) {
				if (!B[i] && !B[i % N + 1] && A[i % N + 1] < 0) {
					B[i] = B[i % N + 1] = 1;
					queries.push_back(i);
				}
			}

			if (queries.empty()) break;
			cout << "Q " << queries.size();
			for (int i : queries) cout << ' ' << i << ' ' << i % N + 1;
			cout << endl;

			string str;
			cin >> str;
			for (int i = 0; i < (int) queries.size(); ++i) {
				A[(queries[i] % N + 1)] = str[i] - '0';
			}
		}

		for (int i = 1; i <= N; ++i) comp[i] = (A[i] ? comp[(i + N - 2) % N + 1] : i);
		for (int i = 1; i <= N; ++i) comp[i] = (A[i] ? comp[(i + N - 2) % N + 1] : i);

		C.clear();
		for (int i = 1; i <= N; ++i) if (A[i] == 0) C.push_back(i);
		for (int i : C) assert(comp[i] == i);

		if (C.size() == 0) {
			for (int i = 1; i <= N; ++i) col[comp[i] = i] = 0;
		} else {
			// part 2
			if (C.size() >= 3) {
				cout << "Q " << (C.size() + 1) / 4 + C.size() / 4;
				for (int i = 2; i < (int) C.size(); i += 4) cout << ' ' << C[i] << ' ' << C[i - 2];
				for (int i = 3; i < (int) C.size(); i += 4) cout << ' ' << C[i] << ' ' << C[i - 2];
				cout << endl;
				string str;
				cin >> str;
				for (int i = 2; i < (int) C.size(); i += 4) A[i] = str[i / 4] - '0';
				for (int i = 3; i < (int) C.size(); i += 4) A[i] = str[(C.size() + 1) / 4 + i / 4] - '0';
			}

			if (C.size() >= 5) { 
				cout << "Q " << (C.size() - 1) / 4 + (C.size() - 2) / 4;
				for (int i = 4; i < (int) C.size(); i += 4) cout << ' ' << C[i] << ' ' << C[i - 2];
				for (int i = 5; i < (int) C.size(); i += 4) cout << ' ' << C[i] << ' ' << C[i - 2];
				cout << endl;
				string str;
				cin >> str;
				for (int i = 4; i < (int) C.size(); i += 4) A[i] = str[i / 4 - 1] - '0';
				for (int i = 5; i < (int) C.size(); i += 4) A[i] = str[(C.size() - 1) / 4 + i / 4 - 1] - '0';
			}

			col[C[0]] = 0, col[C[1]] = 1;
			for (int i = 2; i < (int) C.size(); ++i) col[C[i]] = (A[i] ? col[C[i - 2]] : 3 - col[C[i - 1]] - col[C[i - 2]]);
		}

		for (int i = 0; i < 3; ++i) ans[i].clear();
		for (int i = 1; i <= N; ++i) ans[col[comp[i]]].push_back(i);
		cout << "A " << ans[0].size() << ' ' << ans[1].size() << ' ' << ans[2].size() << endl;
		for (int i = 0; i < 3; ++i) {
			for (int j : ans[i]) cout << j << ' ';
			cout << endl;
		}
	}
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int maximalGap(const vector<int> &V) {
	int res = 0;
	for (int i = 0; i + 1 < V.size(); ++i)
		res = max(res, abs(V[i + 1] - V[i]));
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> RB(2);
	vector<int> &R = RB[0];
	vector<int> &B = RB[1];
	vector<int> G;
	for (int i = 0; i < n; ++i) {
		int p;
		char c;
		cin >> p >> c;
		switch (c) {
		case 'R': R.push_back(p); break;
		case 'G': G.push_back(p); break;
		case 'B': B.push_back(p); break;
		}
	}
	long long ans = 0;
	if (G.empty()) {
		for (auto &&V : RB)
			if (!V.empty())
				ans += V.back() - V.front();
	} else {
		for (auto &&V : RB) {
			if (!V.empty() && V.back() >= G.back()) {
				ans += V.back() - G.back();
				do V.pop_back();
				while (!V.empty() && V.back() >= G.back());
			}
		}
		while (G.size() >= 2) {
			int diff = (G.back() - *(G.rbegin() + 1));
			G.pop_back();
			int sum = 0; // of max
			for (auto &&V : RB) {
				vector<int> T = { G.back() + diff };
				while (!V.empty() && V.back() >= G.back()) {
					T.push_back(V.back());
					V.pop_back();
				}
				T.push_back(G.back());
				sum += maximalGap(T);
			}
			ans += min(2ll * diff, 3ll * diff - sum);
		}
		for (auto &&V : RB)
			if (!V.empty())
				ans += G.back() - V.front();
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> sta[5005];

pair<int, int> station[5005];

int n, m;

int calc(int from, int to) {
	if (to >= from) {
		return to - from;
	}
	return (to + n) - from;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		sta[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		station[i].first = sta[i].size();
		station[i].second = 1e9;
		for (int j = 0; j < sta[i].size(); j++) {
			station[i].second = min(station[i].second, calc(i, sta[i][j]));
		}
	}
	for (int i = 1; i <= n; i++) {
		 int maxi = 0;
		 for (int j = 1; j <= n; j++) {
		 	if (station[j].first == 0) {
		 		continue;
		 	}
		 	maxi = max(maxi, calc(i, j) + (station[j].first - 1) * n + station[j].second);
		 }
		 cout << maxi << " ";
	}
	return 0;
}
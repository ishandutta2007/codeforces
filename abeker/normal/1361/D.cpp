#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 5e5 + 5;
const ld eps = 1e-12;

struct cmp {
	bool operator()(const ld &lhs, const ld &rhs) const {
		return lhs + eps < rhs;
	}
};

int N, K;
map <ld, vector <ld>, cmp> byAngle;
vector <vector <ld>> dist;

ld norm(int x, int y) {
	return sqrt((ld)x * x + (ld)y * y);
}

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x || y)
			byAngle[atan2(y, x)].push_back(norm(x, y));
	}
}

ld solve() {
	for (auto it : byAngle) 
		dist.push_back(it.second);
	
	int origin = 0;
	if (K == N) {
		origin = 1;
		K--;
	}
	
	ld sol = 0;
	for (; origin < 2; origin++) {
		vector <pair <ld, int>> all;
		for (int i = 0; i < dist.size(); i++) {
			sort(dist[i].begin(), dist[i].end(), greater <ld> ());
			for (int j = 0; j < dist[i].size(); j++) 
				all.push_back({(ld)(K - 2 * j - 1 + origin) * dist[i][j], i});
		}
		
		sort(all.begin(), all.end(), greater <pair <ld, int>> ());
		
		int k = 0;
		ld sum = 0;
		vector <int> taken(dist.size(), 0);
		for (; k < K && all[k].first >= 0; k++) {
			taken[all[k].second]++;
			sum += all[k].first;
		}
		
		if (k < K) 
			for (int i = 0; i < dist.size(); i++)
				if (taken[i] < dist[i].size()) {
					sort(dist[i].begin(), dist[i].end());
					for (int j = 0; j < K - k; j++)
						sum += (ld)(K - 2 * (taken[i] + j) - 1 + origin) * dist[i][K - k - j - 1];
					break;
				}
		
		sol = max(sol, sum);
		K--;
	}
	
	return sol;
}

int main() {
	load();
	printf("%.15Lf\n", solve());
	return 0;
}
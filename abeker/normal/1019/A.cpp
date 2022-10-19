#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e3 + 5;

int N, M;
vector <int> cost[MAXN];

ll calc(int x) {
	int tot = cost[1].size() + x;
	ll res = 0;
	vector <int> all;
	int cnt = 0;
	for (int i = 2; i <= M; i++) {
		int tmp = max((int)cost[i].size() - tot + 1, 0);
		for (int j = 0; j < cost[i].size(); j++)
			if (j < tmp) {
				res += cost[i][j];
				cnt++;
			}
			else
				all.push_back(cost[i][j]);
	}
	
	sort(all.begin(), all.end());
	
	for (int i = 0; i < x - cnt; i++)
		res += all[i];
	
	return res;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int p, c;
		scanf("%d%d", &p, &c);
		cost[p].push_back(c);
	}
	
	for (int i = 1; i <= M; i++)
		sort(cost[i].begin(), cost[i].end());
	
	int rest = N - (int)cost[1].size();
	ll ans = 1e18;
	for (int i = 0; i <= rest; i++)
		ans = min(ans, calc(i));
	
	printf("%lld\n", ans);
	
	return 0;
}
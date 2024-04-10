#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;

struct triple {
	int a, b;
	ll c;
	void output() const {
		printf("%d %d %lld\n", a, b, c);
	}
};

int N, M;
ll bal[MAXN];

int main() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		bal[u] -= d;
		bal[v] += d;
	}
	
	vector <int> pos, neg;
	for (int i = 1; i <= N; i++)
		if (bal[i] > 0)
			pos.push_back(i);
		else if (bal[i] < 0)
			neg.push_back(i);
	
	vector <triple> ans;
	while (!pos.empty() && !neg.empty()) {
		int x = pos.back();
		int y = neg.back();
		ll mini = min(abs(bal[x]), abs(bal[y]));
		bal[x] -= mini;
		bal[y] += mini;
		ans.push_back({y, x, mini});
		if (!bal[x])
			pos.pop_back();
		if (!bal[y])
			neg.pop_back();
	}
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		it.output();
	
	return 0;
}
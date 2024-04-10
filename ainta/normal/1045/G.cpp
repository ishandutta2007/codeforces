#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define N_ 101000
#define SZ 131072
#define pii pair<int,int>
using namespace std;
long long res;
int n, K, IQ[N_], C[N_], Num[N_];
struct point {
	int x, r, k, b, e;
	bool operator <(const point &p)const {
		return r < p.r;
	}
}w[N_];
vector<int>BIT[N_];
vector<pii>G[N_];
map<int, int>Map;
void Add(int pv, int a, int b) {
	int sz = BIT[pv].size() - 1;
	while (a <= sz) {
		BIT[pv][a] += b;
		a += (a&-a);
	}
}
int Sum(int pv, int a) {
	int r = 0;
	while (a) {
		r += BIT[pv][a];
		a -= (a&-a);
	}
	return r;
}
int main() {
	int i, j;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &w[i].x, &w[i].r, &w[i].k);
		IQ[i] = w[i].k;
	}

	sort(w + 1, w + n + 1);
	sort(IQ + 1, IQ + n + 1);
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		if (!Map.count(w[i].k))Map[w[i].k] = ++cnt;
		C[Map[w[i].k]]++;
		G[Map[w[i].k]].push_back({ w[i].x,i });
	}
	for (i = 1; i <= cnt; i++) {
		BIT[i].resize(C[i] + 1);
		sort(G[i].begin(), G[i].end());
		for (j = 0; j < G[i].size(); j++)Num[G[i][j].second] = j + 1;
	}
	for (i = n; i >= 1; i--) {
		for (j = w[i].k - K; j <= w[i].k + K; j++) {
			if (Map.count(j)) {
				int x = Map[j];
				pii t1 = { w[i].x - w[i].r,0 };
				pii t2 = { w[i].x + w[i].r + 1,0 };
				int bb = lower_bound(G[x].begin(), G[x].end(), t1) - G[x].begin();
				int ee = lower_bound(G[x].begin(), G[x].end(), t2) - G[x].begin();
				res += Sum(x, ee) - Sum(x, bb);
			}
		}
		Add(Map[w[i].k], Num[i], 1);
	}
	printf("%lld\n", res);
}
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;

int N, M;
vector <int> E[MAXN];
bool bio[MAXN];
int loops, tot;
bool self[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u == v) {
			self[u] = true;
			loops++;
		}
		else {
			E[u].push_back(v);
			E[v].push_back(u);
			tot++;
		}
	}
}

void dfs(int x) {
	bio[x] = true;
	for (auto it : E[x])
		if (!bio[it])
			dfs(it);
}

ll choose(int x) {
	return (ll)x * (x - 1) / 2;
}

ll solve() {
	int cnt = 0;
	for (int i = 1; i <= N; i++)
		if (!bio[i] && (!E[i].empty() || self[i])) {
			dfs(i);
			cnt++;
		}
	
	if (cnt > 1)
		return 0;
	
	ll sol = choose(loops) + (ll)loops * tot;
	for (int i = 1; i <= N; i++)
		sol += choose(E[i].size());
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
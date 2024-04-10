#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MAXK = 6;

int N, K;
vector <int> E[MAXN];
int cnt[MAXN][MAXK];
int subtree[MAXN], depth[MAXN];
ll tot[MAXK];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

void dfs(int x, int p, int d) {
	subtree[x] = 1;
	depth[x] = d;
	cnt[x][d]++;
	for (auto it : E[x])
		if (it != p) {
			dfs(it, x, (d + 1) % K);
			subtree[x] += subtree[it];
			for (int i = 0; i < K; i++)
				cnt[x][i] += cnt[it][i];
		}
}

void calc(int x, int p) {
	int curr[MAXK] = {0};
	for (auto it : E[x])
		if (it != p) {
			for (int i = 0; i < K; i++)
				for (int j = 0; j < K; j++)
					tot[(i + j - 2 * depth[x] % K + K) % K] += (ll)curr[i] * cnt[it][j];
			for (int i = 0; i < K; i++)
				curr[i] += cnt[it][i];
			calc(it, x);
		}
	for (int i = 0; i < K; i++)
		tot[(i - depth[x] + K) % K] += (ll)curr[i];
}

ll solve() {
	dfs(1, 0, 0);
	
	ll sol = 0;
	ll choose = (ll)N * (N - 1) / 2;
	for (int i = 2; i <= N; i++)	
		sol += (ll)subtree[i] * (N - subtree[i]);
	sol -= choose;
	
	calc(1, 0);
	
	for (int i = 0; i < K; i++)
		sol -= tot[(i + 1) % K] * i;
	
	sol /= K;
	sol += choose;
	
	return sol; 
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 31;

int N;
int a[MAXN];
bool bio[MAXN][2 * MAXN][MAXN * MAXN];
vector <int> path, opt;
vector <pii> v;
int sol[2 * MAXN][2 * MAXN];
int limit;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

void dfs(int pos, int sum) {
	int num = path.size();
	if (pos == N) {
		if (sum == num * (num - 1) / 2 && (opt.empty() || path.size() < opt.size()))
			opt = path;
		return;
	}
	if (num > limit || sum > limit * (limit - 1) / 2)
		return;
	if (bio[pos][num][sum])
		return;
	bio[pos][num][sum] = true;
	sum += a[pos];
	if (sum < num * (num + 1) / 2)
		return;
	path.push_back(a[pos]);
	dfs(pos, sum);
	dfs(pos + 1, sum);
	path.pop_back();
}

void solve() {
	sort(a, a + N);
	limit = 2 * a[N - 1] + 1;
	dfs(0, 0);
	if (opt.empty()) {
		puts("=(");
		return;
	}
	
	int nodes = opt.size();
	for (int i = 0; i < nodes; i++)
		v.push_back({opt[i], i});
		
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes - i - 1; j++)
			if (j < v[i].first)
				sol[v[i].second][v[i + j + 1].second] = 1;
			else {
				sol[v[i + j + 1].second][v[i].second] = 1;
				v[i + j + 1].first--;
			}
		sort(v.begin() + i + 1, v.end());
	}
	
	printf("%d\n", nodes);
	for (int i = 0; i < nodes; i++, puts(""))
		for (int j = 0; j < nodes; j++)
			printf("%d", sol[i][j]);
}

int main() {
	load();
	solve();
	return 0;
}
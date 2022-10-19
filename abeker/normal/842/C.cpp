#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
int a[MAXN];
vector <int> E[MAXN];
vector <int> divs[MAXN];
int cnt[MAXN];
int val[MAXN], sol[MAXN];

void init() {
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j += i)
			divs[j].push_back(i);
}

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
}

void dfs(int x, int p, int d) {	
	val[x] = __gcd(val[p], a[x]);
	sol[x] = val[p];
	
	for (auto it : divs[a[x]])
		cnt[it]++;
		
	for (auto it : divs[a[x]])
		if (cnt[it] >= d)
			sol[x] = max(sol[x], it);
					
	for (auto it : E[x])
		if (it != p)
			dfs(it, x, d + 1);
	
	for (auto it : divs[a[x]])
		cnt[it]--;
}

void solve() {
	dfs(1, 0, 0);
	
	sol[1] = a[1];
	for (int i = 1; i <= N; i++)
		printf("%d ", sol[i]);
	puts("");
}

int main() {
	init();
	load();
	solve();
	return 0;
}
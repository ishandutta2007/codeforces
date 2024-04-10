#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1 << 21;

int H, G, N;
int who[MAXN];
pii sorted[MAXN];
int a[MAXN], idx[MAXN];
int height[MAXN], rnk[MAXN];
bool alive[MAXN];
int ptr;

void load() {
	scanf("%d%d", &H, &G);
	N = 1 << H;
	for (int i = 1; i < N; i++)
		scanf("%d", a + i);
}

inline void update(int x) {
	rnk[x] = a[x] ? (a[2 * x] > a[2 * x + 1] ? rnk[2 * x] : rnk[2 * x + 1]) + 1 : 0;
}

void recalc(int x) {
	int lft = 2 * x;
	int rig = 2 * x + 1;
	alive[idx[a[x]]] = false;
	if (a[lft] || a[rig]) {
		if (a[lft] > a[rig]) {
			a[x] = a[lft];
			who[a[x]] = x;
			recalc(lft);
		}
		else {
			a[x] = a[rig];
			who[a[x]] = x;
			recalc(rig);
		}
	}
	else
		a[x] = 0;
	update(x);
	if (a[x] && rnk[x] > height[x] - H + G)
		alive[idx[a[x]]] = true;
}

void solve() {
	ptr = N - 1;
	for (int i = 1; i < N; i++) {
		sorted[i] = {a[i], i};
		alive[i] = true;
	}
	
	sort(sorted + 1, sorted + N);
	
	for (int i = 1; i < N; i++) {
		idx[sorted[i].first] = i;
		who[sorted[i].first] = sorted[i].second;
	}
	
	for (int i = N; i < 2 * N; i++) 
		a[i] = rnk[i] = height[i] = 0;
	
	for (int i = 2 * N - 1; i; i--) {
		if (i < N)
			height[i] = height[2 * i] + 1;
		update(i);
	}
		
	vector <int> ans;
	for (int i = 0; i < N - (1 << G); i++) {
		while (ptr && !alive[ptr])
			ptr--;
		recalc(who[sorted[ptr].first]);
		ans.push_back(who[sorted[ptr].first]);
	}
	
	long long sum = 0;
	for (int i = 1; i < N; i++)
		sum += a[i];
	
	printf("%lld\n", sum);
	for (auto it : ans)
		printf("%d ", it);
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}
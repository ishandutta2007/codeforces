#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e3 + 5;

int N, M, T;
int p[MAXN];
int a[MAXN], b[MAXN];
int par[MAXN], id[MAXN];
bool bio[MAXN];
multiset <pii> S;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < 2 * N; i++)
		scanf("%d", p + i);
	for (int i = 0; i < M; i++)
		scanf("%d%d", a + i, b + i);
	scanf("%d", &T);
}

void init() {
	for (int i = 0; i < 2 * N; i++)
		S.insert({p[i], i});
	
	memset(par, -1, sizeof par);
	for (int i = 0; i < M; i++) {
		a[i]--;
		b[i]--;
		if (p[a[i]] < p[b[i]])
			swap(a[i], b[i]);
		par[a[i]] = b[i];
		par[b[i]] = a[i];
		id[a[i]] = id[b[i]] = i;
	}
}

void choose(int x) {
	S.erase(S.find({p[x], x}));
	printf("%d\n", x + 1);
	fflush(stdout);
}

int get() {
	int x;
	scanf("%d", &x);
	x--;
	S.erase(S.find({p[x], x}));
	return x;
}

void solve1() {
	for (int i = 0; i < M; i++) 
		if (!bio[i]) {
			choose(a[i]);
			assert(get() == b[i]);
		}
	
	while (!S.empty()) {
		choose(S.rbegin() -> second);
		if (S.empty())
			break;
		get();
	}
}

void solve2() {
	for (int i = 0; i < N; i++) {
		int tmp = get();
		if (par[tmp] == -1)
			break;
		choose(par[tmp]);
		bio[id[tmp]] = true;
	}
	solve1();
}

int main() {
	load();
	init();
	if (T == 1)
		solve1();
	else
		solve2();
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N;
int a[MAXN];
int p[MAXN];
ll sol[MAXN];
int dad[MAXN];
bool bio[MAXN];
ll sum[MAXN];
ll maks;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= N; i++)
		scanf("%d", p + i);
}

int find(int x) {
	return x == dad[x] ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (rand() % 2) swap(x, y);
	dad[x] = y;
	sum[y] += sum[x];
}

void solve() {
	for (int i = 1; i <= N; i++) {
		dad[i] = i;
		sum[i] = a[i];
	}
	
	for (int i = N; i; i--) {
		sol[i] = maks;
		if (bio[p[i] - 1]) join(p[i] - 1, p[i]);
		if (bio[p[i] + 1]) join(p[i] + 1, p[i]);
		bio[p[i]] = true;
		maks = max(maks, sum[find(p[i])]);
	}
	
	for (int i = 1; i <= N; i++)
		printf("%lld\n", sol[i]);
}

int main() {
	load();
	solve();
	return 0;
}
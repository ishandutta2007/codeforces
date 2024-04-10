#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const ll INF = 4e18;

int N;
ll T;
ll a[MAXN];
int x[MAXN];
int sum[MAXN];
bool bad[MAXN];
ll lo[MAXN], hi[MAXN];

void load() {
	scanf("%d%lld", &N, &T);
	for (int i = 1; i <= N; i++)
		scanf("%lld", a + i);
	for (int i = 1; i <= N; i++)
		scanf("%d", x + i);
}

void bye() {
	puts("No");
	exit(0);
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (x[i] < i)
			bye();
		sum[i + 1]++;
		sum[x[i] + 1]--;
		bad[x[i] + 1] = true;
	}
	
	for (int i = 1; i <= N; i++) {
		hi[i] = INF;
		lo[i] = 1;
	}
	
	for (int i = 1; i <= N; i++) {
		sum[i] += sum[i - 1];
		if (bad[i] && sum[i])
			bye();
		lo[i] = max(lo[i], a[i] + T);
		if (sum[i])
			lo[i - 1] = max(lo[i - 1], a[i] + T);
		if (bad[i])
			hi[i - 1] = min(hi[i - 1], a[i] + T - 1);
	}
	
	for (int i = 1; i <= N; i++) {
		lo[i] = max(lo[i], lo[i - 1] + 1);
		if (lo[i] > hi[i])
			bye();
	}
	
	puts("Yes");
	for (int i = 1; i <= N; i++)
		printf("%lld ", lo[i]);
	puts("");
}

int main() {
	load();
	solve();	
	return 0;
}
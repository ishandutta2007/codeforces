#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;

int N, M, A, B;
int u[MAXN], v[MAXN];
int compA[MAXN], compB[MAXN];
int dad[MAXN], rnk[MAXN];

void load() {
	scanf("%d%d%d%d", &N, &M, &A, &B);
	for (int i = 0; i < M; i++)
		scanf("%d%d", u + i, v + i);
}

ll choose2(int x) {
	return (ll)x * (x - 1) / 2;
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
}

void label(int node, int *comp) {
	for (int i = 1; i <= N; i++) {
		dad[i] = i;
		rnk[i] = 0;
	}
	for (int i = 0; i < M; i++)
		if (u[i] != node && v[i] != node)
			join(u[i], v[i]);
	for (int i = 1; i <= N; i++)
		comp[i] = find(i);
}

ll solve() {
	label(A, compA);
	label(B, compB);
	
	map <pii, int> cnt;
	vector <int> cntA(N + 1, 0), cntB(N + 1, 0);
	for (int i = 1; i <= N; i++)
		if (i != A && i != B) {
			cntA[compA[i]]++;
			cntB[compB[i]]++;
			cnt[{compA[i], compB[i]}]++;
		}
	
	ll sol = choose2(N - 2);
	for (int i = 1; i <= N; i++)
		sol -= choose2(cntA[i]) + choose2(cntB[i]);
	for (auto it : cnt)
		sol += choose2(it.second);
	
	return sol;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		printf("%lld\n", solve());
	}
	return 0;
}
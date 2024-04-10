#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

int N, M;
int p[MAXN], a[MAXN], b[MAXN];
set <pii> A[5], B[5];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", p + i);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
	
	for (int i = 0; i < N; i++) {
		A[a[i]].insert({p[i], b[i]});
		B[b[i]].insert({p[i], a[i]});
	}
	
	scanf("%d", &M);
	while (M--) {
		int c;
		scanf("%d", &c);
		int sol = INF;
		if (!A[c].empty())
			sol = min(sol, A[c].begin() -> first);
		if (!B[c].empty())
			sol = min(sol, B[c].begin() -> first);
		printf("%d ", sol == INF ? -1 : sol);
		if (sol == INF)
			continue;
		if (sol == A[c].begin() -> first) {
			int val = A[c].begin() -> second;
			A[c].erase(A[c].begin());
			B[val].erase({sol, c});
		}
		if (sol == B[c].begin() -> first) {
			int val = B[c].begin() -> second;
			B[c].erase(B[c].begin());
			A[val].erase({sol, c});
		}
	}
	puts("");
	
	return 0;
}
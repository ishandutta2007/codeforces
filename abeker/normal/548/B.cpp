#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 505;

int N, M, Q;
int mat[MAXN][MAXN];
int maks[MAXN];
multiset <int> S;

void load() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++)
			scanf("%d", mat[i] + j);
}

void update(int row) {
	int &ref = maks[row];
	S.erase(S.find(ref));
	ref = 0;
	int len = 0;
	for (int i = 1; i <= M; i++) {
		len = (len + 1) * mat[row][i];
		ref = max(ref, len);
	}
	S.insert(ref);
}

void solve() {
	for (int i = 1; i <= N; i++) {
		S.insert(0);
		update(i);
	}
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		mat[x][y] ^= 1;
		update(x);
		printf("%d\n", *(--S.end()));
	}
}

int main() {
	load();
	solve();
	return 0;
}
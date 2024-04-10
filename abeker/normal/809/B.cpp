#include <cstdio>
using namespace std;

int N, K;

void load() {
	scanf("%d%d", &N, &K);
}

void out(int type, int x, int y) {
	printf("%d %d %d\n", type, x + 1, y + 1);
	fflush(stdout);
}

bool ask(int x, int y) {
	out(1, x, y);
	char ans[5];
	scanf("%s", ans);
	return ans[0] == 'N';
}

int query(int lo, int hi) {
	if (lo >= hi)
		return -1;
	if (hi - lo == 1)
		return lo;
	int mid = (lo + hi) / 2;
	if ((hi - lo) % 2) 
		return ask(mid - 1, mid + 1) ? query(mid + 1, hi) : query(lo, mid + 1);
	return ask(mid - 1, mid) ? query(mid, hi) : query(lo, mid);
}

void solve() {
	int idx = query(0, N);
	int left = query(0, idx);
	int right = query(idx + 1, N);
	out(2, idx, left == -1 || ask(left, idx) ? right : left);
}

int main() {
	load();
	solve();
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 300005;
const int offset = 1 << 19;

struct tournament {
	int t[2 * offset];
	tournament() {
		memset(t, 0, sizeof t);
	}
	void update(int x, int val) {
		x += offset;
		t[x] = val;
		for (x /= 2; x; x /= 2)
			t[x] = max(t[2 * x], t[2 * x + 1]);
	}
	int query(int x, int lo, int hi, int from, int to) {
		if (lo >= to || hi <= from)
			return 0;
		if (lo >= from && hi <= to)
			return t[x];
		int mid = (lo + hi) / 2;
		return max(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
	}
	int query(int from, int to) {
		return query(1, 0, offset, from, to);
	}
};

int N;
int a[MAXN];
tournament even, odd;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

int get(int len) {
	if (len % 2) {
		if (len == 1)
			return *max_element(a + 1, a + N + 1);
		return odd.query((len + 1) / 2, N - len / 2 + 1);
	}
	return even.query(len / 2, N - len / 2 + 1);
}

void solve() {
	for (int i = 1; i <= N; i++) {
		even.update(i, max(a[i], a[i + 1]));
		odd.update(i, min(a[i], max(a[i - 1], a[i + 1])));
	}
	
	for (int i = 0; i < N; i++)
		printf("%d ", get(N - i));
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}
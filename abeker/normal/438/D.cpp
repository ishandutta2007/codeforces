#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;
const int offset = 1 << 17;

int N, M;
int a[offset];
int t[2 * offset];
ll f[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) 
		scanf("%d", a + i);
}

void add(int x, int val) {
	for (; x < MAXN; x += x & -x)
		f[x] += val;
}

ll get(int x) {
	ll res = 0;
	for (; x; x -= x & -x)
		res += f[x];
	return res;
}

int merge(int l, int r) {
	return a[l] > a[r] ? l : r;
}

void update(int x, int val) {
	add(x, -a[x]);
	a[x] = val;
	add(x, a[x]);
	x += offset;
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return 0;
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void solve() {
	for (int i = 1; i <= N; i++)
		add(i, a[i]);
	
	for (int i = 0; i < offset; i++)
		t[i + offset] = i;
		
	for (int i = offset - 1; i >= 0; i--) 
		t[i] = merge(t[2 * i], t[2 * i + 1]);
	
	while (M--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) 
			printf("%lld\n", get(r) - get(l - 1));
		else if (t == 2) {
			int x;
			scanf("%d", &x);
			int tmp = 0;
			while (1) {
				tmp = query(1, 0, offset, l, r + 1);
				if (a[tmp] < x)
					break;
				update(tmp, a[tmp] % x);
			} 
		}
		else 
			update(l, r);
	}
}

int main() {
	load();
	solve();
	return 0;
}
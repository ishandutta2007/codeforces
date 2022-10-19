#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50005;
const int MAXK = 15;
const int offset = 1 << 16;
const int INF = 0x3f3f3f3f;

struct tournament {
	int t[2 * offset];
	tournament() {
		memset(t, INF, sizeof t);
	}
	void update(int x, int val) {
		x += offset;
		t[x] = val;
		for (x /= 2; x; x /= 2)
			t[x] = min(t[2 * x], t[2 * x + 1]);
	}
	int query(int x, int lo, int hi, int from, int to) {
		if (lo >= to || hi <= from)
			return INF;
		if (lo >= from && hi <= to)
			return t[x];
		int mid = (lo + hi) / 2;
		return min(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
	}
	int query(int from, int to) {
		return query(1, 0, offset, from, to);
	}
};

int N, K;
int a[MAXN][MAXK];
int idx[MAXN], pos[MAXN];
set <int> global, alive;
tournament mini[MAXK], maks[MAXK];
int f[MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++)
			scanf("%d", a[i] + j);
}

bool cmp(const int &lhs, const int &rhs) {
	return a[lhs][0] < a[rhs][0];
}

bool good(int x, int y) {
	return -maks[y].query(0, x) < mini[y].query(x, N); 
}

bool out(int x, int y) {
	if (good(x, y))
		return false;
	global.erase(x);
	if (alive.count(x))
		alive.erase(x);
	return true;
}

void kick_left(int x, int y) {
	while (!global.empty()) {
		//puts("mamice");
		auto it = global.upper_bound(x);
		if (it-- == global.begin())
			break;
		if (!out(*it, y))
			break;
	}
}

void kick_right(int x, int y) {
	while (!global.empty()) {
		//puts("tatice");
		auto it = global.upper_bound(x);
		if (it == global.end())
			break;
		if (!out(*it, y))
			break;
	}
}

void update(int x) {
	for (x++; x < MAXN; x += x & -x)
		f[x]++;
}

int get(int x) {
	int res = 0;
	for (x++; x; x -= x & -x)
		res += f[x];
	return res;
}

void add(int x) {
	update(pos[x]);
	for (int i = 1; i < K; i++) {
		mini[i].update(pos[x], a[x][i]);
		maks[i].update(pos[x], -a[x][i]);
		kick_left(pos[x], i);
		kick_right(pos[x], i);
	}
	if (pos[x] && global.count(pos[x]))
		alive.insert(pos[x]);
}

void solve() {
	for (int i = 0; i < N; i++)
		idx[i] = i;
	
	sort(idx, idx + N, cmp);
	
	for (int i = 0; i < N; i++)
		pos[idx[i]] = i;
	
	for (int i = 1; i < N; i++)
		global.insert(i);
		
	alive.insert(0)	;
	for (int i = 0; i < N; i++) {
		add(i);
		printf("%d\n", i + 1 - get(*alive.rbegin() - 1));
	}
}

int main() {
	load();
	solve();
	return 0;
}
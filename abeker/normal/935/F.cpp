#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const ll INF = 1e18;

struct node {
	int posneg;
	pii posX, posY, negX, negY, mindiff;
};

const node DEF = {0, {INF, INF}, {INF, INF}, {-INF, INF}, {-INF, INF}, {-INF, INF}};

int N, Q;
ll a[MAXN];
node t[2 * offset];
ll ans;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
}

inline void mx(ll &x, ll y) {
	if (x < y)
		x = y;
}

node merge(node lft, node rig) {
	node res;
	res.posneg = lft.posneg + rig.posneg;
	res.posX = lft.posX.second < rig.posX.second ? lft.posX : rig.posX;
	res.posY = lft.posY.second < rig.posY.second ? lft.posY : rig.posY;
	res.negX = lft.negX.first > rig.negX.first ? lft.negX : rig.negX;
	res.negY = lft.negY.first > rig.negY.first ? lft.negY : rig.negY;
	res.mindiff = lft.mindiff.second - lft.mindiff.first < rig.mindiff.second - rig.mindiff.first ? lft.mindiff : rig.mindiff;
	return res;
}

node get(ll x, ll y) {
	node res = DEF;
	res.posneg = x >= 0 && y <= 0;
	if (x >= 0)
		res.posX = {x, y};
	if (y >= 0)
		res.posY = {x, y};
	if (x <= 0)
		res.negX = {x, y};
	if (y <= 0)
		res.negY = {x, y};
	if (x <= 0 && y >= 0)
		res.mindiff = {x, y};
	return res;
}

void change(int x) {
	t[x + offset] = get(a[x], a[x + 1]);
	for (x = (x + offset) / 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return DEF;
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void update(int from, int to, int x) {
	ans -= abs(a[from - 1]) + abs(a[to]);
	a[from - 1] += x;
	a[to] -= x;
	ans += abs(a[from - 1]) + abs(a[to]);
	if (from > 1)
		change(from - 2);
	change(from - 1);
	change(to - 1);
	change(to);
}

ll get(pii p, int x) {
	return abs(p.first + x) + abs(p.second - x) - abs(p.first) - abs(p.second);
}

ll query(int from, int to, int x) {
	node tmp = query(1, 0, offset, from - 1, to);
	if (tmp.posneg)
		return 2 * x;
	ll res = -2 * x;
	if (tmp.posX != DEF.posX)
		mx(res, get(tmp.posX, x));
	if (tmp.posY != DEF.posY)
		mx(res, get(tmp.posY, x));
	if (tmp.negX != DEF.negX)
		mx(res, get(tmp.negX, x));
	if (tmp.negY != DEF.negY)
		mx(res, get(tmp.negY, x));
	if (tmp.mindiff != DEF.mindiff)
		mx(res, get(tmp.mindiff, x));
	return res;
}

void solve() {
	for (int i = N - 1; i; i--) {
		a[i] -= a[i - 1];
		ans += abs(a[i]);
	}
	
	for (int i = 0; i < 2 * offset; i++)
		t[i] = DEF;
		
	for (int i = 1; i < N - 1; i++)
		t[i + offset] = get(a[i], a[i + 1]);
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	scanf("%d", &Q);
	while (Q--) {
		int t, l, r, x;
		scanf("%d%d%d%d", &t, &l, &r, &x);
		if (t == 1)
			printf("%lld\n", ans + query(l, r, x));
		else
			update(l, r, x);
	}
}

int main() {
	load();
	solve();
	return 0;
}
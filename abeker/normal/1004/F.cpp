#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;

struct node {
	ll ans;
	vector <pii> pref, suff;
};

int N, M, X;
node t[2 * offset];

vector <pii> gen(vector <pii> a, vector <pii> b) {
	if (a.empty())
		return b;
	vector <pii> r = a;
	for (auto it : b) {
		pii tmp = {it.first, it.second | a.back().second};
		if (tmp.second == r.back().second)
			r[(int)r.size() - 1].first += it.first;
		else	
			r.push_back(tmp);
	}
	return r;
}

node merge(node l, node r) {
	ll res = l.ans + r.ans;
	int ptr = (int)r.pref.size(), sum = 0;
	for (auto it : l.suff) {
		for (; ptr > 0 && (it.second | r.pref[ptr - 1].second) >= X; ptr--)
			sum += r.pref[ptr - 1].first;
		res += (ll)it.first * sum;
	}
	
	return {res, gen(l.pref, r.pref), gen(r.suff, l.suff)};
}

node get(int val) {
	return {val >= X, {{1, val}}, {{1, val}}};
}

void update(int x, int val) {
	x += offset;
	t[x] = get(val);
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return {0, {}, {}};
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void load() {
	scanf("%d%d%d", &N, &M, &X);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		t[i + offset] = get(tmp);
	}
}

void solve() {
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	while (M--) {
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		if (type == 1)
			update(--x, y);
		else
			printf("%lld\n", query(1, 0, offset, --x, y).ans); 
	}
}

int main() {
	load();
	solve();
	return 0;
}
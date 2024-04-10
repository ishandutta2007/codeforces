#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;
const int offset = 1 << 20;

struct node {
	ll sum, tot;
	node(ll sum, ll tot) : sum(sum), tot(tot) {}
	node() : sum(0), tot(0) {}
};

int N, K, M;
vector <int> in[MAXN], out[MAXN];
pii plan[offset];
int cores[offset];
int pos[offset];
node t[2 * offset];

void load() {
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d%d%d%d", &l, &r, cores + i, &plan[i].first);
		plan[i].second = i;
		in[l].push_back(i);
		out[r].push_back(i);
	}
}

node merge(node l, node r) {
	return node(l.sum + r.sum, l.tot + r.tot);
}

void update(int x, ll v) {
	t[x + offset].sum += v * cores[plan[x].second];
	t[x + offset].tot += v * cores[plan[x].second] * plan[x].first;
	for (x = (x + offset) / 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

ll query(int x, int k) {
	if (x >= offset)
		return (ll)min(cores[plan[x - offset].second], k) * plan[x - offset].first;
	if (t[2 * x].sum >= k)
		return query(2 * x, k);
	return t[2 * x].tot + query(2 * x + 1, k - t[2 * x].sum);
}

ll solve() {
	sort(plan, plan + M);
	for (int i = 0; i < M; i++)
		pos[plan[i].second] = i;
		
	ll sol = 0;
	for (int i = 1; i <= N; i++) {
		for (auto it : in[i])
			update(pos[it], 1);
		sol += query(1, K);
		for (auto it : out[i])
			update(pos[it], -1);
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
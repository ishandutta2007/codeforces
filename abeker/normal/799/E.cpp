#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;
const ll INF = 1e18;

struct node {
	int cnt;
	ll sum;
};

int N, M, K;
int cost[MAXN];	
bool like[2][MAXN];
vector <int> v[2][2];
node t[2 * offset];
int idx[MAXN], pos[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", cost + i);
	for (int i = 0; i < 2; i++) {
		int a;
		scanf("%d", &a);
		while (a--) {
			int x;
			scanf("%d", &x);
			like[i][--x] = true;
		}
	}
}

node merge(node l, node r) {
	return {l.cnt + r.cnt, l.sum + r.sum};
}

void update(int x, int val) {
	x += offset;
	t[x] = {val, val * cost[idx[x - offset]]};
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

ll query(int x, int lo, int hi, int k) {
	if (!k)
		return 0;
	if (x >= offset)
		return t[x].sum;
	int mid = (lo + hi) / 2;
	if (t[2 * x].cnt >= k)
		return query(2 * x, lo, mid, k);
	return t[2 * x].sum + query(2 * x + 1, mid, hi, k - t[2 * x].cnt);
}

bool cmp(const int &lhs, const int &rhs) {
	return cost[lhs] < cost[rhs];
}

ll solve() {
	if (M < K)
		return -1;
		
	for (int i = 0; i < N; i++)
		idx[i] = i;
		
	sort(idx, idx + N, cmp);
	
	for (int i = 0; i < N; i++)
		pos[idx[i]] = i;
		
	for (int i = 0; i < N; i++)
		v[like[0][i]][like[1][i]].push_back(i);
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			sort(v[i][j].begin(), v[i][j].end(), cmp);
	
	int lo = max(K - min((int)min(v[0][1].size(), v[1][0].size()), M - K), 0);
	
	if (lo > v[1][1].size())
		return -1;
	
	ll curr = 0;
	for (int i = 0; i < lo; i++)
		curr += cost[v[1][1][i]];
	
	for (int i = lo; i < v[1][1].size(); i++)
		update(pos[v[1][1][i]], 1);
		
	for (int i = 0; i < 2; i++) {
		for (; v[i][i ^ 1].size() > K - lo; v[i][i ^ 1].pop_back())
			update(pos[v[i][i ^ 1].back()], 1);
		for (auto it : v[i][i ^ 1])
			curr += cost[it];
	}
	
	for (auto it : v[0][0])
		update(pos[it], 1);
	
	ll sol = INF;
	int need = M - 2 * K + lo;
	for (int i = lo; need >= 0; i++) {
		sol = min(sol, curr + query(1, 0, offset, need));
		if (i == v[1][1].size())
			break;
		curr += cost[v[1][1][i]];
		update(pos[v[1][1][i]], 0);
		need--;
		for (int j = 0; j < 2; j++)
			if (!v[j][j ^ 1].empty()) {
				curr -= cost[v[j][j ^ 1].back()];
				update(pos[v[j][j ^ 1].back()], 1);
				v[j][j ^ 1].pop_back();
				need++;
			}
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
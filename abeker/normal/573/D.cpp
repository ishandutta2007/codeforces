#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e4 + 5;
const int offset = 1 << 15;
const ll INF = 1e18;

struct node {
	int l, r;
	ll dist[4][4];
	node() {
		l = r = MAXN;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				dist[i][j] = -INF;
	}
};

int N, Q;
pii war[MAXN], hor[MAXN];
int posW[MAXN], posH[MAXN];
int perm[MAXN];
ll cost[MAXN][4];
node t[2 * offset];

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) 
		scanf("%d", &war[i].first);
	for (int i = 1; i <= N; i++)
		scanf("%d", &hor[i].first);
}

node merge(node lft, node rig) {
	if (rig.r > N)
		return lft;
	node res;
	res.l = lft.l;
	res.r = rig.r;
	int bl = min(3, lft.r - lft.l);
	int br = min(3, rig.r - rig.l);
	int b = min(3, res.r - res.l);
	for (int i = 0; i <= b; i++)
		for (int j = 0; j <= b; j++) {
			int diff = rig.r - j - lft.l - i;
			if (!diff)
				res.dist[i][j] = 0;
			else if (diff > 0)
				for (int k = 0; k <= bl; k++)
					for (int l = 0; l <= br; l++) {
						int delta = rig.l + l - lft.r + k;
						if (delta <= 4)
							res.dist[i][j] = max(res.dist[i][j], lft.dist[i][k] + cost[rig.l + l][delta - 1] + rig.dist[l][j]);
					}
		}
	return res;
}

void update(int x) {
	x += offset;
	t[x].l = t[x].r = x - offset;
	t[x].dist[0][0] = 0;
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return node();
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void modify(int x) {
	for (int i = x; i < x + 4 && i <= N; i++)
		for (int j = 0; j < 4; j++) {
			cost[i][j] = -INF;
			if (j >= i)
				continue;
			vector <int> v;
			for (int k = j; k >= 0; k--)
				v.push_back(i - k);
			do {
				bool ok = true;
				ll tmp = 0;
				for (int k = 0; k <= j; k++) {
					ok &= perm[i - k] != v[k];
					tmp += (ll)war[i - k].first * hor[v[k]].first;
				}
				if (ok)
					cost[i][j] = max(cost[i][j], tmp);
			} while (next_permutation(v.begin(), v.end()));
		}
}

void solve() {
	for (int i = 1; i <= N; i++)
		war[i].second = hor[i].second = i;
		
	sort(war + 1, war + N + 1);
	sort(hor + 1, hor + N + 1);
	
	for (int i = 1; i <= N; i++) {
		posW[war[i].second] = i;
		posH[hor[i].second] = i;
	}
	
	for (int i = 1; i <= N; i++)
		perm[i] = posH[war[i].second];
	
	for (int i = 1; i <= N; i++) 
		modify(i);
	
	for (int i = 0; i < offset; i++)
		update(i);
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
	
	while (Q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = posW[a];
		b = posW[b];	
		swap(perm[a], perm[b]);
		modify(a);
		modify(b);
		update(a);
		update(b);
		printf("%lld\n", query(1, 0, offset, 0, N + 1).dist[0][0]);
	}
}

int main() {
	load();
	solve();
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
vector <pii> E[MAXN];
int a[MAXN];
ll depth[MAXN];
int disc[MAXN], fin[MAXN];
int timer = 1;
vector <ll> comp;
vector <int> in[MAXN], out[MAXN];
int f[2 * MAXN];
int node[MAXN];
int sol[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 2; i <= N; i++) {
		int p, w;
		scanf("%d%d", &p, &w);
		E[p].push_back(pii(i, w));
		E[i].push_back(pii(p, w));
	}
}

void dfs(int x, int p) {
	disc[x] = timer++;
	for (pii it : E[x]) 
		if (it.first != p) {
			depth[it.first] = depth[x] + it.second;
			dfs(it.first, x);
		}
	fin[x] = timer;
}

int get(ll val) {
	return lower_bound(comp.begin(), comp.end(), val) - comp.begin();
}

void update(int x, int val) {
	for (x++; x < 2 * MAXN; x += x & -x)
		f[x] += val;
}

int query(int x) {
	int res = 0;
	for (x++; x; x -= x & -x)
		res += f[x];
	return res;
}

void solve() {
	dfs(1, 0);
	
	for (int i = 1; i <= N; i++) {
		comp.push_back(depth[i]);
		comp.push_back(depth[i] - a[i]);
	}
	sort(comp.begin(), comp.end());
	
	for (int i = 1; i <= N; i++) {
		in[disc[i]].push_back(i);
		out[fin[i]].push_back(i);
		node[disc[i]] = i;
	}
	
	for (int i = 1; i <= N + 1; i++) {
		for (int it : out[i])
			sol[it] += query(get(depth[it]));
		for (int it : in[i])
			sol[it] -= query(get(depth[it]));
		update(get(depth[node[i]] - a[node[i]]), 1);
	}
	
	for (int i = 1; i <= N; i++)
		printf("%d ", sol[i] - 1);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}
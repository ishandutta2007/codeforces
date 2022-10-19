#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
vector <pii> E[MAXN];
bool bio[MAXN];
int path[MAXN];
vector <int> cyc;
vector <int> L, R;
int trie[MAXN * 28][2];
int tot;

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		E[x].push_back({y, w});
		E[y].push_back({x, w});
	}
}

void dfs(int x, int d, pii p) {
	bio[x] = true;
	path[x] = d;
	for (auto it : E[x])
		if (!bio[it.first])
			dfs(it.first, d ^ it.second, {x, it.second});
		else if (it != p) 
			cyc.push_back(path[x] ^ path[it.first] ^ it.second);
}

void insert(int curr, int bit, int val) {
  if (bit == -1) 
    return;
  int tmp = val >> bit & 1;
  if (trie[curr][tmp] == -1) 
    trie[curr][tmp] = tot++;
  insert(trie[curr][tmp], bit - 1, val);
}

int query(int curr, int bit, int val) {
  if (bit == -1) 
		return 0;
  int tmp = val >> bit & 1;
  if (trie[curr][tmp] == -1) 
    return (query(trie[curr][tmp ^ 1], bit - 1, val) | 1 << bit);
  return query(trie[curr][tmp], bit - 1, val);
}

void norm(vector <int> &V) {
	sort(V.begin(), V.end());
	V.resize(unique(V.begin(), V.end()) - V.begin());
	for (auto it : V)
		printf("%d ", it);
	puts("");
}

int solve() {
	dfs(1, 0, {-1, -1});
	
	int ind = 0, sz = cyc.size();
	for (int i = 0; i < 28; i++) 
		for (int j = ind; j < sz; j++)
			if (cyc[j] >> i & 1) {
			 	swap(cyc[ind], cyc[j]);
			 	for (int k = 0; k < sz; k++)
			 		if (k != ind && cyc[k] >> i & 1) 
			 			cyc[k] ^= cyc[ind];
			 	ind++;
			 	break;
			}
		
	while (cyc.size() < 28)
		cyc.push_back(0);
	
	for (int i = 0; i < 1 << 14; i++) {
		int left = 0, right = 0;
		for (int j = 0; j < 14; j++)
			if (i >> j & 1) {
				left ^= cyc[j];
				right ^= cyc[j + 14];
			}
		L.push_back(left);
		R.push_back(right);
	}
	
	memset(trie, -1, sizeof trie);
	for (auto it : R)
		insert(0, 28, it);
	
	int sol = path[N];
	for (auto it : L) 
		sol = min(sol, query(0, 28, path[N] ^ it));
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}
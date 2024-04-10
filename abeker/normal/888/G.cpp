#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MAXB = 30;

int N;
int a[MAXN];
int trie[MAXN * MAXB][2];
int depth[MAXN * MAXB];
vector <int> subtree[MAXN * MAXB];
int curr;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

void insert(int num, int node, int pos, int dep) {
	subtree[node].push_back(num);
	depth[node] = dep;
	if (pos < 0)
		return;
	int bit = num >> pos & 1;
	if (trie[node][bit] == -1)
		trie[node][bit] = ++curr;
	insert(num, trie[node][bit], pos - 1, dep + 1);
}

int calc(int val, int node) {
	int pos = MAXB - depth[node] - 1;
	if (pos < 0)
		return 0;
	int bit = val >> pos & 1;
	if (trie[node][bit] != -1 && !subtree[trie[node][bit]].empty())
		return calc(val, trie[node][bit]);
	assert(trie[node][bit ^ 1] != -1);
	return calc(val, trie[node][bit ^ 1]) ^ 1 << pos;
}

ll solve() {
	memset(trie, -1, sizeof trie);
	for (int i = 0; i < N; i++)
		insert(a[i], 0, MAXB - 1, 0);
	
	ll sol = 0;
	for (int i = 0; i <= curr; i++)
		if (trie[i][0] != -1 && trie[i][1] != -1) {
			int mini = 1 << MAXB;
			for (auto it : subtree[trie[i][0]])
				mini = min(mini, calc(it, trie[i][1]) ^ 1 << MAXB - depth[i] - 1);
			sol += mini;
		}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
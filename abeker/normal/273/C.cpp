#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 300005;

int N, M;
vector <int> adj[MAXN];
int where[MAXN];
int cnt[MAXN];

void update(int x) {
	cnt[x] = 0;
	for (int y : adj[x])
		cnt[x] += where[y] == where[x];
}

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (cnt[lhs] != cnt[rhs])
			return cnt[lhs] > cnt[rhs];
		return lhs < rhs;
	}
};

set <int, cmp> S;

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		update(i);
		S.insert(i);
	}
		
	while (1) {
		int who = *S.begin();
		if (cnt[who] <= 1)
			break;
		S.erase(who);
		for (int en : adj[who])
			S.erase(en);
		where[who] ^= 1;
		update(who);
		for (int en : adj[who])
			update(en);
		S.insert(who);
		for (int en : adj[who])
			S.insert(en);
	}
	
	for (int i = 1; i <= N; i++)
		printf("%d", where[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}
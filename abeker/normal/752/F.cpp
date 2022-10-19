#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 200005;

int N, K;
vector <int> E[MAXN];
bool home[MAXN];
vector <vector <int> > all;
vector <int> curr;

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (all[lhs].size() != all[rhs].size())
			return all[lhs].size() < all[rhs].size();
		return lhs < rhs;
	}
};

set <int, cmp> S;

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (int i = 0; i < 2 * K; i++) {
		int x;
		scanf("%d", &x);
		home[x] = true;
	}
}

void go(int x, int p) {
	if (home[x])
		curr.push_back(x);
	for (int nxt : E[x])
		if (nxt != p)
			go(nxt, x);
}

void finish(int root) {
	for (int child : E[root]) {
		go(child, root);
		all.push_back(curr);
		curr.clear();
	}
	if (home[root]) {
		curr.push_back(root);
		all.push_back(curr);
	}
	
	for (int i = 0; i < all.size(); i++)	
		if (!all[i].empty())
			S.insert(i);
	
	printf("1\n%d\n", root);
	while (!S.empty()) {
		int mn = *S.begin();
		int mx = *S.rbegin();
		S.erase(mn);
		S.erase(mx);
		printf("%d %d %d\n", all[mn].back(), all[mx].back(), root);
		all[mn].pop_back();
		all[mx].pop_back();
		if (!all[mn].empty())
			S.insert(mn);
		if (!all[mx].empty())
			S.insert(mx);
	}
	
	exit(0);
}

int dfs(int x, int p) {
	bool ok = true;
	int cnt = home[x];
	for (int nxt : E[x])
		if (nxt != p) {
			int tmp = dfs(nxt, x);
			ok &= tmp <= K;
			cnt += tmp;
		}
	ok &= cnt >= K;
	if (ok) 
		finish(x);
	return cnt;
}

void solve() {
	dfs(1, 0);
}

int main() {
	load();
	solve();
	return 0;
}
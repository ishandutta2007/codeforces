#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1 << 19;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

int N, A[MAXN];
int B[MAXN];
set<pii> bit[MAXN];
bool vis[MAXN];
int ans[MAXN];

void dfs (int x) {
	static int cur = 0;
	if (x == N + 1 || vis[x]) {
		return;
	}
	vis[x] = true;
	dfs(B[x]);
	for (int i = A[x] - 1; i; i &= i - 1) {
		while (!bit[i].empty() && bit[i].rbegin() -> fi > x) {
			int t = bit[i].rbegin() -> se;
			bit[i].erase(--bit[i].end());
			if (!vis[t]) {
				dfs(t);
			}
		}
	}
	ans[x] = ++cur;
}

int main() {
	cin>>N;
	fill_n(B + 1, N, N + 1);
	for (int i = 1; i <= N; i++) {
		cin>>A[i];
		if (A[i] == -1) {
			A[i] = N + 1;
		}
		B[A[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		pii p(B[i], i);
		for (int j = i; j < MAXN; j += (j & -j)) {
			bit[j].insert(p);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout<<ans[i]<<endl;
	}
	puts("");
}
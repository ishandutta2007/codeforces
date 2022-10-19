#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int t;
#define MAXN 200010
vector<int> adj[MAXN];
vector<int> options[MAXN];
vector<ll> memo[MAXN];
void find_options(int a, vector<int> pre) {
	options[a] = pre;
	memo[a] = { -1, -1 };
	if (adj[a].empty()) return;
	int lower = pre[0]/adj[a].size();
	int upper = pre.back()/adj[a].size() + !!(pre.back()%adj[a].size());
	D("%d: %d %d\n", a, lower, upper);
	assert(upper-lower <= 1);
	for (auto b : adj[a]) {
		if (lower == upper) find_options(b, {lower});
		else find_options(b, {lower, upper});
	}
}
ll s[MAXN];
ll dp(int a, int whichone) {
	if (memo[a][whichone] >= 0) return memo[a][whichone];
	if (adj[a].empty()) {
		return s[a]*options[a][whichone];
	}
	int numBig = options[a][whichone] % adj[a].size();
	int numSmall = adj[a].size()-numBig;
	if (numBig == 0 && whichone) {
		swap(numBig, numSmall);
	}
	ll sum = s[a]*options[a][whichone];
	vector<ll> diff;
	for (auto b : adj[a]) {
		sum += dp(b, 0);
		if (numBig) diff.push_back(dp(b, 1)-dp(b, 0));
	}
	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());
	for (int i = 0; i < numBig; i++) sum += diff[i];
	return memo[a][whichone] = sum;
}
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n, k;
		D("here\n");
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			options[i].clear();
		}
		for (int i = 2; i <= n; i++) {
			int p;
			scanf("%d", &p);
			adj[p].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &s[i]);
		}
		find_options(1, { k });
		printf("%lld\n", dp(1, 0));
	}
}
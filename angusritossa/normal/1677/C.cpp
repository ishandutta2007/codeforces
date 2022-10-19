#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 200010
typedef long long ll;
int num;
int seen[MAXN], upto;
vector<int> adj[MAXN];
int A[MAXN], B[MAXN];
void dfs(int a) {
	if (seen[a] == upto) return;
	num++;
	seen[a] = upto;
	for (auto b : adj[a]) dfs(b);
}
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		++upto;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
		for (int i = 1; i <= n; i++) {
			adj[A[i]].push_back(B[i]);
			adj[B[i]].push_back(A[i]);
		}
		int numOdd = 0;
		for (int i = 1; i <= n; i++) {
			num = 0;
			dfs(i);
			if (num%2) numOdd++;
		}
		int mid = (n+1)/2;
		vector<ll> options;
		for (int i = 1; i <= n; i++) {
			options.push_back({abs(mid-i)});
		}
		sort(options.begin(), options.end());
		ll ans = 0;
		for (int i = numOdd; i < n; i++) {
			ans += 2*options[i];
		}
		printf("%lld\n", ans);
	}
}
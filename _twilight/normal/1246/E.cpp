#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 16, S = 1 << N;

#define pii pair<int, int>

int n, K;
bitset<2005> f[S];
vector<int> G[N];

int a[N];
int x[N], y[N]; 
priority_queue<pii> Q;
void solve() {
	int pos = 0;
	for (int i = n - 1; ~i; i--) {
		pos += y[i];
		Q.push(pii(pos, a[x[i]]));
	}
	puts("YES");
	while (Q.size() > 1) {
		pii A = Q.top(); Q.pop();
		pii B = Q.top(); Q.pop();
		assert(A.first == B.first);
		printf("%d %d\n", A.second, B.second);
		A.second += B.second;
		while (!(A.second % K))
			A.second /= K, A.first--;
		assert(A.first >= 0);
		Q.push(A);
	}
	exit(0);
}

void dfs(int d, int S, int sum) {
	if (S == (1 << n) - 1) {
		if (sum == 1) {
			solve();
		}
		return;
	}
	if (f[S].test(sum))
		return;
	f[S].set(sum);
	for (int i = 0; i < n; i++) {
		if (!((S >> i) & 1)) {
			x[d] = i;
			y[d] = 0;
			int nsum = sum + a[i];
			while (!(nsum % K)) {
				dfs(d + 1, S | (1 << i), nsum);
				nsum /= K, y[d]++;
			}
			dfs(d + 1, S | (1 << i), nsum);
		}
	}
}

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	dfs(0, 0, 0);
	puts("NO");
	return 0;
}
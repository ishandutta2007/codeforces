#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 3e5 + 5;

int n;
int a[N];
ll f[N];
int g[N];

vector<int> ans;
void work(int p) {
	if (!a[p] || !a[p + 1])
		return;
	ans.push_back(p);
	int d = min(a[p], a[p + 1]);
//	__cost += d;
	a[p] -= d, a[p + 1] -= d;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	f[0] = 0, f[1] = 0, g[1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		f[i] = f[i - 2] + a[i - 1], g[i] = 2;
		if (i > 2 && f[i - 3] + max(a[i - 1], a[i - 2]) < f[i]) {
			f[i] = f[i - 3] + max(a[i - 1], a[i - 2]);
			g[i] = 3;
		}
	}
	int pos = (f[n] < f[n + 1]) ? (n) : (n + 1);
	for ( ; pos > 1; pos -= g[pos]) {
		if (g[pos] == 3)
			work(pos - 2);
		work(pos - 1);
		work(pos - g[pos]);
	}
//	cerr << min(f[n], f[n + 1]) << '\n';
//	cerr << "cost: " << __cost << '\n';
	printf("%d\n", (signed) ans.size());
	for (auto x : ans) {
		printf("%d\n", x);
	}
	return 0;
}
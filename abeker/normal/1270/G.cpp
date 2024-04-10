#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N;
int a[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", a + i);
		a[i] = i - a[i];
	}
}

void solve() {
	int x = 0;
	vector <int> path;
	vector <bool> bio(N, false);
	for (; !bio[x]; x = a[x]) {
		path.push_back(x);
		bio[x] = true;
	}
	
	vector <int> cycle = {x};
	for (; path.back() != x; path.pop_back())
		cycle.push_back(path.back());
	
	printf("%d\n", cycle.size());
	for (auto it : cycle)
		printf("%d ", it + 1);
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}
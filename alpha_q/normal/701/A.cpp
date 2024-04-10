#include <bits/stdc++.h>

using namespace std;

const int N = 110;

bool vis[N];

int main (int argc, char const *argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	int n, a[N], sum = 0;
	map <int, priority_queue <int> > pos;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i), sum += a[i], pos[a[i]].push(i);
		
	}
	sum /= (n >> 1);

	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		int now = pos[sum - a[i]].top();
		pos[sum - a[i]].pop();
		vis[i] = vis[now] = 1;
		printf("%d %d\n", i, now);
	}
	return 0;
}
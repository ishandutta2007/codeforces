#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;

int N, K;
char s[MAXN];
int a[MAXN];
set <int> curr;

void load() {
	scanf("%d%d%s", &N, &K, s + 1);
}

void bye() {
	puts("-1");
	exit(0);
}

void update(int x) {
	if (x <= 0 || x >= N)
		return;
	if (a[x] && !a[x + 1])
		curr.insert(x);
	else
		curr.erase(x);
}

void solve() {
	for (int i = 1; i <= N; i++)
		a[i] = s[i] == 'R';
	
	int inv = 0, sum = 0;
	for (int i = 1; i <= N; i++) {
		if (!a[i])
			inv += sum;
		sum += a[i];
	}
	
	if (inv < K)
		bye();
	
	for (int i = 1; i < N; i++)
		update(i);
		
	vector <vector <int>> ans(K + 1);
	for (int i = 1; i <= K; i++) {
		int take = min((int)curr.size(), inv - K + i);
		assert(take);
		inv -= take;
		for (auto it : curr) {
			if (!take)
				break;
			ans[i].push_back(it);
			swap(a[it], a[it + 1]);
			take--;
		}
		for (auto it : ans[i])
			for (int k = -1; k <= 1; k++)
				update(it + k);
	}

	if (inv)
		bye();
	
	for (int i = 1; i <= K; i++) {
		printf("%d ", ans[i].size());
		for (auto it : ans[i])
			printf("%d ", it);
		puts("");
	}
}

int main() {
	load();
	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
int ver[MAXN];
map <int, int> rig;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", ver + i);
	while (M--) {
		int x1, x2, y;
		scanf("%d%d%d", &x1, &x2, &y);
		if (x1 == 1)
			rig[y] = x2;
	}
}

int solve() {
	vector <int> all;
	for (auto it : rig)
		if (it.second)
			all.push_back(it.second);
	
	sort(all.begin(), all.end());
	ver[N++] = 1e9;
	sort(ver, ver + N);
	
	int sol = 1e9, ptr = 0;
	for (int i = 0; i < N; i++) {
		for (; ptr < all.size() && all[ptr] < ver[i]; ptr++);
		sol = min(sol, i + (int)all.size() - ptr);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}
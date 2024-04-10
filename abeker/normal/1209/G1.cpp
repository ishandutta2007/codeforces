#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, Q;
int a[MAXN];
vector <int> pos[MAXN];
int bad[MAXN];

void load() {
	scanf("%d%d", &N, &Q);
	assert(!Q);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

int solve() {
	for (int i = 0; i < N; i++)
		pos[a[i]].push_back(i);
	
	for (int i = 0; i < MAXN; i++)
		if (!pos[i].empty()) {
			bad[pos[i][0]]++;
			bad[pos[i].back()]--;
		}
	
	int sol = N, mx = 0;
	unordered_map <int, int> freq;
	for (int i = 0; i < N; i++) {
		mx = max(mx, ++freq[a[i]]);
		if (i)
			bad[i] += bad[i - 1];
		if (!bad[i]) {
			sol -= mx;
			freq.clear();
			mx = 0;
		}
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}
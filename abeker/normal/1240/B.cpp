#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N;
int a[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

int solve() {
	vector <int> mini(N + 1, N);
	vector <int> maks(N + 1, -1);
	for (int i = 0; i < N; i++) {
		mini[a[i]] = min(mini[a[i]], i);
		maks[a[i]] = max(maks[a[i]], i);
	}
	
	int len = 0, opt = 0;
	int cnt = 0, last = -1;
	for (int i = 1; i <= N; i++) {
		if (maks[i] == -1)
			continue;
		if (last >= mini[i]) 
			len = 0;
		last = maks[i];
		opt = max(opt, ++len);
		cnt++;
	}
	
	return cnt - opt;
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		load();
		printf("%d\n", solve());
	}
	return 0;
}
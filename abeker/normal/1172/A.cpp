#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int pile[MAXN];
int pos[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%*d");
	for (int i = 1; i <= N; i++) {
		scanf("%d", pile + i);
		pos[pile[i]] = i;
	}
}

int one_round() {
	int st = pos[1] ? pos[1] : N + 1;
	for (int i = st; i <= N; i++)
		if (pile[i] != i - st + 1)
			return 2 * N;
	for (int i = 1; i < st; i++)
		if (pos[N - st + 1 + i] >= i)
			return 2 * N;
	return st - 1;
}

int two_rounds() {
	int mx = 0;
	for (int i = 1; i <= N; i++) {
		if (mx >= N - i + 1)
			return 2 * N - i + 2;
		mx = max(mx, pos[i] - i);
	}
	return N + 1;
}

int main() {
	load();
	printf("%d\n", min(one_round(), two_rounds()));
	return 0;
}
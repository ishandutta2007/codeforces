#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N;
char s[MAXN];
int a[MAXN], pref[MAXN];
int suff[MAXN];

void load() {
	scanf("%d%s", &N, s + 1);
}

int solve() {
	for (int i = 1; i <= N; i++) {
		a[i] = s[i] == '(' ? 1 : -1;
		pref[i] = pref[i - 1] + a[i];
	}
	
	for (int i = N; i; i--) {
		suff[i] = pref[i];
		if (i < N)
			suff[i] = min(suff[i], suff[i + 1]);
	}
		
	int sol = 0;
	for (int i = 1; i <= N; i++) {
		sol += 2 * a[i] == pref[N] && suff[i] >= 2 * a[i];
		if (pref[i] < 0)
			break;
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}
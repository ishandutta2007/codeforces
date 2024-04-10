#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int H;
int a[MAXN];
int first[MAXN];
int dad[2][MAXN];

void load() {
	scanf("%d", &H);
	for (int i = 0; i <= H; i++)
		scanf("%d", a + i);
}

void solve() {
	int N = 1;
	bool ok = true;
	for (int i = 0; i <= H; i++) {
		first[i] = N;
		if (i) {
			for (int j = 0; j < a[i]; j++)
				dad[0][N + j] = dad[1][N + j] = first[i - 1];
			if (a[i] > 1 && a[i - 1] > 1 && ok) {
				ok = false;
				dad[1][N]++;
			}
		}
		N += a[i];
	}
	
	if (ok) {
		puts("perfect");
		return;
	}
	
	puts("ambiguous");
	for (int i = 0; i < 2; i++, puts(""))
		for (int j = 1; j < N; j++)
			printf("%d ", dad[i][j]);	
}

int main() {
	load();
	solve();
	return 0;
}
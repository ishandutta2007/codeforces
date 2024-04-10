#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int N;
bool has[MAXN][MAXN];

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		int r;
		scanf("%d", &r);
		while (r--) {
			int tram;
			scanf("%d", &tram);
			has[i][tram] = true;
		}
	}
	
	for (int i = 0; i < MAXN; i++) {
		bool ok = true;
		for (int j = 0; j < N; j++)
			ok &= has[j][i];
		if (ok)
			printf("%d ", i);
	}
	puts("");
	
	return 0;
}
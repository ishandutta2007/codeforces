#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int p[MAXN];
int lo[MAXN];

void init() {
	for (int i = 2; i < MAXN; i++)
		if (!p[i])
			for (int j = i; j < MAXN; j += i)
				if (!p[j])
					p[j] = i;
	
	for (int i = 2; i < MAXN; i++) {
		int x = i;
		lo[i] = i;
		while (x > 1) {
			int tmp = p[x];
			lo[i] = min(lo[i], max(i - tmp + 1, tmp + 1));
			while (!(x % tmp))
				x /= tmp;
		}
	}
}

int main() {
	init();	
	
	int N;
	scanf("%d", &N);
	
	int sol = N;
	for (int i = lo[N]; i <= N; i++)
		sol = min(sol, lo[i]);
	
	printf("%d\n", sol);
	
	return 0;
}
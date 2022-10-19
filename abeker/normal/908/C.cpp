#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 1005;

int N, R;
int x[MAXN];
ld sol[MAXN];

int main() {
	scanf("%d%d", &N, &R);
	for (int i = 0; i < N; i++)
		scanf("%d", x + i);
	
	for (int i = 0; i < N; i++) {
		sol[i] = R;
		for (int j = 0; j < i; j++) {
			int dist = abs(x[i] - x[j]);
			if (dist <= 2 * R)
				sol[i] = max(sol[i], sol[j] + sqrt((ld)4 * R * R - (ld)dist * dist));
		}
		printf("%.15Lf ", sol[i]);
	}
	puts("");
	
	return 0;
}
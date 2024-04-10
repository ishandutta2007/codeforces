#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, S;
int deg[MAXN];

int main() {
	scanf("%d%d", &N, &S);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		deg[a]++;
		deg[b]++;
	}
	
	int cnt = 0;
	for (int i = 1; i <= N; i++)
		cnt += deg[i] == 1;
		
	printf("%.10lf\n", (double)2 * S / cnt);
	
	return 0;
}
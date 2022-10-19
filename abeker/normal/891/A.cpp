#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int N;
int a[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (a[i] == 1)
			cnt++;
		
	if (cnt) {
		printf("%d\n", N - cnt);
		return 0;
	}
	
	int mini = N + 1;
	for (int i = 0; i < N; i++) {
		int g = 0;
		for (int j = i; j < N; j++) {
			g = __gcd(g, a[j]);
			if (g == 1) {
				mini = min(mini, j - i + 1);
				break;
			}
		}
	}
	
	printf("%d\n", mini == N + 1 ? -1 : mini + N - 2);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;

int N;
int a[MAXN], b[MAXN], c[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	for (int i = 0; i < N; i++)
		b[i] = a[i];
	
	sort(b, b + N);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (b[j] == a[i]) {
				printf("%d ", b[(j + 1) % N]);
				break;
			}
	puts("");
	
	return 0;
}
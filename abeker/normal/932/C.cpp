#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N, A, B;
int p[MAXN];

void finish(int x) {
	for (int i = 0; i < N; i++)
		p[i] = i;
	
	for (int i = 0; i < x; i += A)
		rotate(p + i, p + i + 1, p + i + A);
	
	for (int i = x; i < N; i += B)
		rotate(p + i, p + i + 1, p + i + B);
	
	for (int i = 0; i < N; i++)
		printf("%d ", ++p[i]);
	puts("");
}

int main() {
	scanf("%d%d%d", &N, &A, &B);
		
	for (int i = 0; i <= N; i++)
		if (!(i % A) && !((N - i) % B)) {
			finish(i);
			return 0;
		}
	
	puts("-1");
	
	return 0;
}
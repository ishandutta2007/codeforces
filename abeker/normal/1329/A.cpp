#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
int l[MAXN], p[MAXN];

void bye() {
	puts("-1");
	exit(0);
}

int main() {
	scanf("%d%d", &N, &M);	
	for (int i = 0; i < M; i++)
		scanf("%d", l + i);
	
	long long sum = 0;
	for (int i = 0; i < M; i++) {
		if (l[i] + i > N)
			bye();
		sum += l[i];
	}
	
	if (sum < N)
		bye();
	
	p[M] = 1;
	for (int i = M - 1; i >= 0; i--) 
		p[i] = min(N - i - l[i] + 1, p[i + 1] + l[i + 1]);
	
	for (int i = 0; i < M; i++)
		printf("%d ", p[i]);
	puts("");
	
	return 0;
}
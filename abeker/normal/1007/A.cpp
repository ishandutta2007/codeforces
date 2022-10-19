#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	sort(a, a + N, greater <int> ());
	
	int ptr = 0, sol = 0;
	for (int i = 0; i < N; i++) {
		while (ptr < N && a[i] <= a[ptr])
			ptr++;
		sol += ptr++ < N;
	}
	
	printf("%d\n", sol);
	
	return 0;
}
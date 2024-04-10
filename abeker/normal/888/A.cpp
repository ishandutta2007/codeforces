#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int N;
int a[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	int sol = 0;
	for (int i = 1; i < N - 1; i++)
		sol += (a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]);
	
	printf("%d\n", sol);
	
	return 0;
}
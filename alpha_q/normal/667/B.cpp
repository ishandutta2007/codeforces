#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;

int N; long long A[MAX];

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &N); 
	for (int i = 1; i <= N; i++) scanf("%I64d", A + i);
	sort (A + 1, A + 1 + N);

	long long Sum = 0;
	for (int i = 1; i < N; i++) Sum += A[i];
	printf("%I64d\n", A[N] - Sum + 1);
	return 0;
}
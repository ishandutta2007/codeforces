#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	if (N > M) {
		puts("0");
		return 0;
	}
	vector <int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	
	int ans = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			ans = (long long)ans * abs(a[i] - a[j]) % M;
	
	printf("%d\n", ans);
	
	return 0;
}
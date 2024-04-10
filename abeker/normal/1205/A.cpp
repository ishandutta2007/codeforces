#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	if (!(N % 2)) {
		puts("NO");
		return 0;
	}
	
	vector <int> ans(2 * N, 0);
	for (int i = 0; i < N; i++) {
		ans[i] = 2 * i + 1;
		ans[i + N] = 2 * i + 2;
		if (i % 2)
			swap(ans[i], ans[i + N]);
	}
	
	puts("YES");
	for (auto it : ans)
		printf("%d ", it);
	puts("");
	
	return 0;
}
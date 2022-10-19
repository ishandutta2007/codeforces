#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N;
		scanf("%d", &N);
		vector <int> a(N), b(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &b[i]);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (auto it : a)
			printf("%d ", it);
		puts("");
		for (auto it : b)
			printf("%d ", it);
		puts("");
	}
	return 0;
}
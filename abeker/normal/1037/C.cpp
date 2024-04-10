#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N;
char a[MAXN], b[MAXN];

int main() {
	scanf("%d%s%s", &N, a, b);
	
	int ans = 0;
	for (int i = 0; i < N; i++)
		if (a[i] != b[i]) {
			ans++;
			if (i < N - 1 && a[i] != a[i + 1])
				i++;
		}
		
	printf("%d\n", ans);
	
	return 0;
}
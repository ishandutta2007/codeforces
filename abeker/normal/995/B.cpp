#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

int N;
int a[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= 2 * N; i++)
		scanf("%d", a + i);
	
	int sol = 0;
	for (int i = 1; i < 2 * N; i += 2) {
		int pos = 0;
		for (int j = i + 1; j <= 2 * N; j++)
			if (a[j] == a[i])
				pos = j;
		sol += pos - i - 1;
		rotate(a + i + 1, a + pos, a + pos + 1);
	}
	
	printf("%d\n", sol);
	
	return 0;
}
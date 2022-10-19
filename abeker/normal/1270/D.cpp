#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	
	map <int, int> cnt;
	for (int i = 1; i <= K + 1; i++) {
		printf("? ");
		for (int j = 1; j <= K + 1; j++)
			if (j != i)
				printf("%d ", j);
		puts("");
		fflush(stdout);
		int pos, val;
		scanf("%d%d", &pos, &val);
		cnt[val]++;
	}
	
	printf("! %d\n", cnt.rbegin() -> second);
	fflush(stdout);
	
	return 0;
}
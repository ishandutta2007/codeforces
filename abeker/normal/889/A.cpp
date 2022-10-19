#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int cnt[MAXN];

int main() {
	scanf("%d", &N);
	int sol = 1;
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		if (cnt[t])
			sol++;
		else	
			cnt[t]++; 
	}

	printf("%d\n", sol);
	
	return 0;
}
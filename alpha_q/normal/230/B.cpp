#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

bool mark[N];
int n; long long x;

void sieve (void) {
	mark[0] = mark[1] = 1;
	for (int i = 2; i * i < N; ++i) if (not mark[i])
		for (int j = i * i; j < N; j += i) mark[j] = 1; 
}

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);	
	
	sieve();
	scanf("%d", &n); while (n--) {
		scanf("%lld", &x);
		long long sq = sqrt(x);

		if (sq * sq != x) {
			printf("NO\n");
			continue;
		}

		if (mark[sq]) {
			printf("NO\n");
			continue;
		}

		printf("YES\n");
	}
	return 0; 
}
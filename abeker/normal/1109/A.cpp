#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 21;

int N;
int cnt[2][MAX];

int main() {
	scanf("%d", &N);
	cnt[0][0]++;
	int pref = 0;
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		pref ^= x;
		ans += cnt[i % 2][pref]++;
	}
	
	printf("%lld\n", ans);
		
	return 0;
}
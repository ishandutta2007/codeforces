#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll N, K;
int M;
ll pos[MAXN];

int main() {
	scanf("%lld%d%lld", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%lld", pos + i);
		pos[i]--;
	}
	
	int ans = 0;
	int rem = 0, ptr = 0;
	while (ptr < M) {
		ll page = (pos[ptr] - rem) / K;
		int cnt = 0;
		for (; ptr < M && (pos[ptr] - rem) / K == page; ptr++)
			cnt++;
		rem += cnt;
		ans++;	
	}
	
	printf("%d\n", ans);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N, K;
int a[MAXN], l[MAXN];
map <int, int> cnt[15];

int len(int x) {
	return x ? len(x / 10) + 1 : 0;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	for (int i = 0; i < N; i++) {
		l[i] = len(a[i]);
		cnt[l[i]][a[i] % K]++;
	}
	
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		int num = a[i];
		for (int j = 1; j <= 10; j++) {
			num = (ll)10 * num % K;
			auto it = cnt[j].find((K - num) % K);
			if (it != cnt[j].end())
				ans += it -> second;
			if (j == l[i] && !((a[i] + num) % K))
				ans--;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

char buff[MAX];
unordered_map <int, int> cnt;

int main() {
	int N;
	scanf("%d", &N);
	long long ans = 0;
	while (N--) {
		scanf("%s", buff);
		int mask = 0;
		for (int i = 0; buff[i]; i++)
			mask ^= 1 << buff[i] - 'a';
		ans += cnt[mask];
		for (int i = 0; i < 26; i++)
			ans += cnt[mask ^ 1 << i];
		cnt[mask]++;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
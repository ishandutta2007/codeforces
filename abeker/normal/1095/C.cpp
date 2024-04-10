#include <bits/stdc++.h>
using namespace std;

multiset <int> pot;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	
	for (int i = 0; i < 30; i++)
		if (N >> i & 1)
			pot.insert(i);
			
	if (pot.size() > K) {
		puts("NO");
		return 0;
	}
	
	while (pot.size() < K) {
		int x = *pot.rbegin();
		if (!x) {
			puts("NO");
			return 0;
		}
		pot.erase(pot.find(x));
		pot.insert(x - 1);
		pot.insert(x - 1);
	}
	
	puts("YES");
	for (auto it : pot)
		printf("%d ", 1 << it);
	puts("");
	
	return 0;
}
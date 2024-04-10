#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N;
		scanf("%d", &N);
		ll sum = 0, val = 0;
		while (N--) {
			int x;
			scanf("%d", &x);
			sum += x;
			val ^= x;
		}
		printf("2\n%lld %lld\n", val, sum + val);
	}
	return 0;
}
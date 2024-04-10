#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
set <ll> ans;

ll calc(int x) {
	int k = N / x;
	return k + (ll)k * (k - 1) / 2 * x;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i * i <= N; i++)
		if (!(N % i)) {
			ans.insert(calc(i));
			ans.insert(calc(N / i));
		}
	
	for (auto it : ans)
		printf("%lld ", it);
	puts("");
	
	return 0;
}
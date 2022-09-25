#include<bits/stdc++.h>

using namespace std;

int main() {
	long long l, r;
	scanf("%lld %lld", &l, &r);
	
	int ans = 0;
	for (int i = 2; i < 61; i++)
		for (int j = 0; j < i - 1; j++)
			if (l <= (1ll << i) - 1 - (1ll << j) && (1ll << i) - 1 - (1ll << j) <= r)
				ans++;
	
	printf("%d\n", ans);
	
	return 0;
}
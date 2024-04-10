#include <bits/stdc++.h>

using namespace std;

const char s[] = "codeforces";

int a[42];

int main() {
	long long k;
	ignore = scanf("%lld", &k);
	
	int n = strlen(s);
	fill(a, a + n, 1);
	
	for (int i = 0; true; i++) {
		long long cnt = 1;
		for (int j = 0; j < n; j++) cnt *= a[j];
		
		if (cnt >= k) break;
	
		a[i % n]++;
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < a[i]; j++)
			printf("%c", s[i]);
	
	printf("\n");
	
	return 0;
}
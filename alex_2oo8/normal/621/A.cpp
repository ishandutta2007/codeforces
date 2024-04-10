#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	long long sum = 0;
	int minOdd = 1000000000;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		sum += a;
		if (a % 2 == 1) minOdd = min(minOdd, a);
	}
	
	if (sum % 2 == 1) sum -= minOdd;
	
	printf("%lld\n", sum);
	
	return 0;
}
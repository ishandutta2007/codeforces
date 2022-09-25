#include<bits/stdc++.h>

using namespace std;

const int MX = 10000000;

long long n[MX], m[MX];

int main() {
	long long x;
	scanf("%I64d", &x);
	
	int k = 0;
	long long sum = 0;
	for (int i = 1; x >= i * 1LL * i; i++) {
		x -= i * 1LL * i;
		sum += i;
		
		if (x % sum == 0) {
			n[k] = i;
			m[k] = i + x / sum;
			
			k++;
		}
	}
	
	for (int i = k - 1; i >= 0; i--)
		if (n[i] != m[i]) {
			n[k] = m[i];
			m[k] = n[i];
			
			k++;
		}
	
	printf("%d\n", k);
	for (int i = 0; i < k; i++) printf("%I64d %I64d\n", n[i], m[i]);
	
	return 0;
}
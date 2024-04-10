#include <bits/stdc++.h>
using namespace std;

bool good(int x) {
	int cnt = 0;
	for (; !(x % 2); x /= 2)
		cnt++;
	return x == (1 << cnt + 1) - 1;
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = N; i; i--)
		if (good(i) && !(N % i)) {
			printf("%d\n", i);
			return 0;
		}
		
	return 0;
}
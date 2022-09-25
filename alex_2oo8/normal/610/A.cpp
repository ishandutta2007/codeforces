#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	if (n % 2 == 1) printf("0\n");
	else printf("%d\n", n / 4 - 1 + n / 2 % 2);
	
	return 0;
}
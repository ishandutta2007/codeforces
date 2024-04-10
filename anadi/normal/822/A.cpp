#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

int a, b;
LL x;

int main(){
	scanf("%d %d", &a, &b);
	x = 1LL;
	for(int i = 2; i <= min(a, b); ++i)
		x *= 1LL * i;
	printf("%lld\n", x);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL n, m;

int main(){
	scanf("%lld %lld", &n, &m);
	if(n > m)
		swap(n, m);
	
	if(n == 1){
		if(m%6 == 0)
			printf("%d\n", m);
		else if(m%6 == 5)
			printf("%d\n", m - 1);
		else if(m%6 == 4)
			printf("%d\n", m - 2);
		else
			printf("%d\n", m - m%6);
		return 0;
	}
	
	if(n == 2){
		if(m <= 2)
			puts("0");
		else if(m == 3)
			puts("4");
		else if(m == 7)
			puts("12");
		else
			printf("%lld\n", 1LL * n * m);
		return 0;
	}
	
	if(n%2 == 0 || m%2 == 0){
		printf("%lld\n", 1LL * n * m);
		return 0;
	}
	
	printf("%lld\n", 1LL * n * m - 1);
	return 0;
}
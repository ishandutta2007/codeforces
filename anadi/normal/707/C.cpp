#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define PLL pair <LL, LL>
#define PDD pair <D, D>

const int N = 1e5 + 7;

LL n;

int main(){
	scanf("%I64d", &n);
	
	if(n <= 2){
		puts("-1");
		return 0;
	}
	
	if(n%2 == 1){
		n *= n;
		n--;
		n /= 2LL;
		printf("%I64d %I64d\n", n, n + 1);
	}
	else{
		n *= n;
		n -= 4LL;
		n /= 4LL;
		printf("%I64d %I64d\n", n, n + 2);
	}

	return 0;
}
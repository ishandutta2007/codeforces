#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define PLL pair <LL, LL>
#define pb push_back

int main(){
	int n, a, b, c, d;
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	
	LL res = 0LL;
	for(int i = 1; i <= n; ++i){
		int now = i + b - c;
		++res;
		if(now < 1 || now > n){
			--res;
			continue;
		}
		now = i + a - d;
		if(now < 1 || now > n){
			--res;
			continue;
		}
		now = i + a + b - c - d;
		if(now < 1 || now > n){
			--res;
			continue;
		}
	}
	
	res *= (LL)n;
	printf("%I64d\n", res);
	return 0;
}
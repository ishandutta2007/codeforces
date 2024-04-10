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
const LL INF = 1e18 + 19LL;

int main(){
	LL a, b;
	scanf("%lld %lld", &a, &b);
	
	for(int i = 1; i <= b; ++i)
		if(a%i != i - 1){
			puts("No");
			return 0;
		}
	
	puts("Yes");
	return 0;
}
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

int main(){
	int n;
	scanf("%d", &n);
	int pt = 1, res = 0;
	while(pt <= n){
		n -= pt;
		pt += pt;
		++res;
	}
	
	if(n > 0)
		++res;
	printf("%d\n", res);
	return 0;
}
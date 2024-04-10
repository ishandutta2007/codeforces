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

int n, m;
LL k;

int main(){
	scanf("%d %d %lld", &n, &m, &k);
	if(k < n){
		printf("%lld 1\n", k + 1);
		return 0;
	}
	
	if(k == n){
		printf("%d 2\n", n);
		return 0;
	}
	
	k -= n;
	int ile = k / (m - 1);
	
	printf("%d ", n - ile);
	k -= ile;
	
	if(m == 2){
		puts("2");
		return 0;
	}
	
	k %= 2 * m - 4;
	if(k <= m - 2)
		printf("%lld\n", k + 2);
	else
		printf("%lld\n", m - (k - m + 2));
	return 0;
}
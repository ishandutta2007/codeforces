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
const int MOD = 1e5;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	printf("%d\n", n + 1);

	int add = 0;
	for(int i = n; i >= 1; --i){
		in[i] += add;
		int v = in[i]%MOD;
		
		int diff = (i - v + MOD)%MOD;
		printf("1 %d %d\n", i, diff);
		add += diff;
	}
	
	printf("2 %d %d\n", n, MOD);
	return 0;
}
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
const int T = 1 << 20;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	int last = 0;
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		
		last += a;
		printf("%d ", last / m);
		last %= m;
	}

	return 0;
}
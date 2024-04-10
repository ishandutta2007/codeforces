#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, p;
long long val[30];
map <long long, int> M;

int main(){
	scanf("%d %d", &n, &p);
	for(int i = 1; i < 100 * 1000; ++i){
		int cur = n - i * p;
		int t = __builtin_popcount(cur);
		
		if(t <= i && i <= cur){
			printf("%d\n", i);
			exit(0);
		}
	}
	
	puts("-1");
	return 0;
}
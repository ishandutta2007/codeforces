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

void solve(){
	int n;
	scanf("%d", &n);
	if(n & 1){
		printf("7");
		n -= 3;
	}
	
	while(n > 0){
		printf("1");
		n -= 2;
	}
	
	puts("");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
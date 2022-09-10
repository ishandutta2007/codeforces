#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;
 
#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;

LL n, k;
int m;
LL input[N];

int main(){
	scanf("%lld %d %lld", &n, &m, &k);
	for(int i = 1; i <= m; ++i)
		scanf("%lld", &input[i]);
	
	int ans = 0;
	for(int i = 1; i <= m; ++i){
		int wsk = i;
		while(wsk < m && (input[wsk + 1] - i) / k == (input[i] - i) / k)
			++wsk;
		
		++ans; i = wsk;
	}
	
	printf("%d\n", ans);
	return 0;
}
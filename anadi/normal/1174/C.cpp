#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, cnt;
int color[N];

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		if(color[i])	continue;
		color[i] = ++cnt;
		
		for(int j = i + i; j <= n; j += i)
			color[j] = cnt;
	}
	
	for(int i = 2; i <= n; ++i)
		printf("%d ", color[i]);

	puts("");
	return 0;
}
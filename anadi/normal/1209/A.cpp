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

int n;
bool is[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		is[a] = true;
	}
	
	int res = 0;
	for(int i = 1; i <= 100; ++i){
		if(!is[i])	continue;
		for(int j = i; j <= 100; j += i)
			is[j] = false;
		++res;
	}
	
	printf("%d\n", res);
	return 0;
}
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

int n;

int main(){
	scanf("%d", &n);
	int cur = 0;
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		if(cur < a){
			printf("%d\n", i);
			return 0;
		}

		if(cur == a)
			++cur;
	}
	
	puts("-1");
	return 0;
}
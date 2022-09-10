#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	if(n == k){
		while(n--)
			printf("1");

		puts("");
		exit(0);
	}
	
	if(k == 1){
		for(int i = 0; i + 1 < n; ++i)
			printf("0");
		puts("1");
		return 0;
	}
	
	if(n == k + 2){
		for(int i = 0; i < n; ++i)
			printf("%d", i%2);

		puts("");
		exit(0);
	}
	
	int cycle = (n - k) / 2 + 1;
	for(int i = 0; i < n; ++i){
		if(i%cycle == 0 || i%cycle == cycle - 1)
			printf("1");
		else
			printf("0");
	}
	
	puts("");
	return 0;
}
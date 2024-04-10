#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double DD;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PDD pair <DD, DD>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	if(k == 1 || n < 4 || k > 3){
		puts("-1");
		return 0;
	}
	
	if(n == 4){
		if(k == 2){
			puts("-1");
			return 0;
		}

		printf("3\n1 2\n2 3\n3 4");
		return 0;
	}
	
	if(k == 2){
		printf("%d\n", n - 1);
		for(int i = 1; i < n; ++i)
			printf("%d %d\n", i, i + 1);
		return 0;
	}
	
	if(n == 5){
		puts("5");
		for(int i = 1; i < n; ++i)
			printf("%d %d\n", i, i + 1);
		puts("1 3");
		return 0;
	}
	
	if(k == 3){
		printf("%d\n", 2 * n - 5);
		for(int i = 1; i < n; ++i)
			printf("%d %d\n", i, i + 1);
		puts("1 3");
		for(int i = 6; i <= n; ++i)
			printf("4 %d\n", i);
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

int n, sum;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		sum += a;
	}
	
	if(n == 1)
		sum == 1 ? puts("YES") : puts("NO");
	else
		sum == n - 1 ? puts("YES") : puts("NO");
	return 0;
}
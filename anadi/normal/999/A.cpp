#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int tab[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	
	int res = 0;
	for(int j = 1; j <= n; ++j)
		if(tab[j] <= m)
			++res;
		else
			break;
	
	if(res == n){
		printf("%d\n", n);
		return 0;
	}
	
	for(int j = n; j >= 1; --j)
		if(tab[j] <= m)
			++res;
		else
			break;
	printf("%d\n", res);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int inf = 1e9 + 7;

int n, k;
int tab[N];

int main(){
	scanf("%d %d", &n, &k);
	int mn = inf;
	LL sum = 0LL;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]),
		sum += tab[i],
		mn = min(mn, tab[i]);
	
	for(int i = 1; i <= n; ++i)
		if(tab[i]%k != mn%k){
			puts("-1");
			return 0;
		}
	
	printf("%lld\n", (sum - 1LL * n * mn) / k);
	return 0;
}
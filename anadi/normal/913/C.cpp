#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, L;
int tab[N];

int main(){
	scanf("%d %d", &n, &L);
	for(int i = 0; i < n; ++i){
		scanf("%d", &tab[i]);
		if(i)
			tab[i] = min(tab[i], 2 * tab[i - 1]);
	}
	
	long long int result = 1LL * INF * INF, cur = 0;
	for(int i = n - 1; i >= 0; --i){
		int cnt = (L - 1) / (1 << i) + 1;
		result = min(result, cur + 1LL * cnt * tab[i]);
		
		if(cnt * (1 << i) > L)
			--cnt;

		cur += 1LL * cnt * tab[i];
		L -= cnt * (1 << i);
	}
	
	printf("%lld\n", result);
	return 0;
}
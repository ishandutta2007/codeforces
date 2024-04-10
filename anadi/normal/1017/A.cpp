#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII  pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
PII tab[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		tab[i] = {a + b + c + d, i};
		tab[i].st *= -1;
	}
	
	sort(tab + 1, tab + n + 1);
	for(int i = 1; i <= n; ++i)
		if(tab[i].nd == 1)
			printf("%d\n", i);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, s;
int deg[N];

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		deg[u]++;
		deg[v]++;
	}
	
	int lf = 0;
	for(int i = 1; i <= n; ++i)
		lf += deg[i] == 1;
	
	printf("%.15Lf\n", 2.0 * (D)s / (long double)lf);
	return 0;
}
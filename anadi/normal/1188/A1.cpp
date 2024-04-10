#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int deg[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		deg[u]++, deg[v]++;
	}
	
	for(int i = 1; i <= n; ++i)
		if(deg[i] == 2){
			puts("NO");
			return 0;
		}
	
	puts("YES");
	return 0;
}
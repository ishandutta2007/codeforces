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
const LL INF = 1e18 + 19LL;

int n;
int tab[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	for(int i = 1; i <= n; ++i){
		if(tab[tab[tab[i]]] == i){
			puts("YES");
			return 0;
		}
	}
	
	puts("NO");
	return 0;
}
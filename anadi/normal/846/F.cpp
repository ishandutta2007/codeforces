#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, m;
int tab[N];
int nast[N];
int last[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	
	for(int i = n; i >= 1; --i){
		nast[i] = last[tab[i]] == 0 ? n + 1 : last[tab[i]];
		last[tab[i]] = i;
	}
	
	LL res = 0LL, curS = 0LL;
	int ile_diff = 0;
	for(int i = 1; i <= n; ++i){
		if(last[tab[i]] == i)
			++ile_diff;
		curS += ile_diff;
	}
	
	for(int i = 1; i <= n; ++i){
		res += curS;
		curS -= nast[i] - i;
	}
	
	assert(curS == 0LL);
	res = 2LL * res - n;
	printf("%.10lf\n", D(res) / D(1LL * n * n));
	return 0;
}
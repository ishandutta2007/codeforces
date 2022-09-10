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

int n, m;
int tab[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		tab[a] = 1;
	}
	
	int res = 0;
	for(int i = 0; i < m; ++i)
		if(tab[i] == 0)
			++res;
	
	res += tab[m] > 0;
	printf("%d\n", res);
	return 0;
}
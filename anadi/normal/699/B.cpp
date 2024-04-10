#include <bits/stdc++.h>

using namespace std;

typedef double LD;
typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define pb push_back
#define PLL pair <LL, LL>
#define pb push_back

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7LL;
const int mxn = 1e5 + 7;

int n, m;
int y[mxn];
int x[mxn];
char mapa[1009][1009];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", mapa[i] + 1);
	
	int ile = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(mapa[i][j] == '*'){
				++x[i];
				++y[j];
				++ile;
			}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(x[i] + y[j] + (mapa[i][j] == '*' ? -1 : 0) == ile){
				puts("YES");
				printf("%d %d\n", i, j);
				return 0;
			}
	
	puts("NO");
	return 0;
}
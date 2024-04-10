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
const int inf = 1e9 + 9;

int n, m;
int tab[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; ++i)
		scanf("%d", &tab[i]);
	sort(tab + 1, tab + 2 * n + 1);
	
	if(tab[n] < tab[n + 1])
		puts("YES");
	else
		puts("NO");
	return 0;
}
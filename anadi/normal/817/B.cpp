#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int N = 1e5 + 7;

int n;
int tab[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	sort(tab + 1, tab + n + 1);
	
	int wsk = 3;
	while(wsk <= n && tab[wsk] == tab[3])
		++wsk;
	wsk--;
	
	LL res = 1LL;
	if(tab[1] == tab[wsk])
		res = 1LL * wsk * (wsk - 1) * (wsk - 2) / 6LL;
	else if(tab[2] == tab[wsk])
		res = 1LL * (wsk - 1) * (wsk - 2) / 2LL;
	else
		res = 1LL * (wsk - 2);
	
	printf("%lld\n", res);
	return 0;
}
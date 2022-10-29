//http://codeforces.com/contest/547/problem/B

#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int a[212345];
int tab[212345];
int bat[212345];
int rdm[212345], ans[212345];
#define mid ((bot + top)/2)

int
main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i < n; i++)
		tab[i] = bat[i] = i;

	for(int i = 0; i < n; i++)
		while(tab[i] != 0 && a[i] <= a[tab[i]-1])
			tab[i] = tab[tab[i]-1];
	for(int i = n-1; i >= 0; i--)
		while(bat[i] != n-1 && a[i] <= a[bat[i]+1])
			bat[i] = bat[bat[i]+1];

	for(int i = 0; i < n; i++)
		ans[bat[i] - tab[i] + 1] = max(ans[bat[i] - tab[i] + 1], a[i]);

	for(int i = n; i > 0; i--)
		ans[i] = max(ans[i], ans[i+1]);
	
	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	
	
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;

int n, k;
int tab[N];

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	sort(tab + 1, tab + n + 1);
	
	int res = 0;
	for(int i = 1; i <= n; ++i){
		while(2 * k < tab[i])
			++res,
			k *= 2;
		k = max(k, tab[i]);
	}
	
	printf("%d\n", res);
	return 0;
}
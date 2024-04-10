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

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, m;
int tab[N], pref[N], suf[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		pref[i] = tab[i] == 0 ? 1 : 0;
		pref[i] += pref[i - 1];
	}
	
	for(int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] + tab[i];
	
	int res = 0;
	for(int i = 0; i <= n; ++i)
		res = max(res, pref[i] + suf[i + 1]);
	printf("%d\n", res);
	return 0;
}
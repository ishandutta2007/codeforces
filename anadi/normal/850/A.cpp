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

const int N = 1007;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, m;
int tab[N][5];

int main(){
	scanf("%d", &n);
	if(n > 33){
		puts("0");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 5; ++j)
			scanf("%d", &tab[i][j]);
	
	vector <int> res;
	for(int i = 1; i <= n; ++i){
		bool ans = true;
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k){
				if(i == j || j == k || i == k)
					continue;
				int cur = 0;
				for(int ii = 0; ii < 5; ++ii)
					cur += (tab[j][ii] - tab[i][ii]) * (tab[k][ii] - tab[i][ii]);
				if(cur > 0)
					ans = false;
			}
		
		if(ans)
			res.pb(i);
	}
	
	printf("%d\n", res.size());
	for(int v: res)
		printf("%d ", v);
	return 0;
}
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
LL tab[N];
LL bestRes = 0LL;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &tab[i - 1]);
	
	LL curS = 0LL;
	int res1 = 0, res2 = 0, res3 = 0;
	for(int i = 0; i <= n; ++i){
		LL curBest = 0LL, allBest = 0LL;
		int x = i, y = i, start = i;
		for(int j = i + 1; j <= n; ++j){
			curBest += tab[j - 1];
			if(curBest > allBest){
				allBest = curBest;
				x = start, y = j;
			}
			
			if(curBest < 0)
				curBest = 0, start = j;
		}
		
		if(allBest + curS > bestRes){
			bestRes = allBest + curS;
			res1 = i, res2 = x, res3 = y;
		}

		curS += tab[i];
	}
	
	printf("%d %d %d\n", res1, res2, res3);
	return 0;
}
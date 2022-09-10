#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int inf = 1e9 + 9;

int n;
int tab[N];

int main(){
	scanf("%d", &n); int mini = inf;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		mini = min(mini, tab[i]);
	}
	
	int res = inf, last = -inf;
	for(int i = 1; i <= n; ++i){
		if(tab[i] != mini)
			continue;
		
		res = min(res, i - last);
		last = i;
	}
	
	printf("%d\n", res);
	return 0;
}
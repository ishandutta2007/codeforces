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
const int inf = 1e9 + 9;

int n, m;
int tab[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		m += tab[i] == 1;
	}
	
	if(m == n){
		puts("0");
		return 0;
	}
	
	if(m > 0){
		printf("%d\n", n - m);
		return 0;
	}
	
	int l = n + 1;
	for(int i = 1; i <= n; ++i){
		int cur = tab[i];
		for(int j = i + 1; j <= n; ++j){
			cur = __gcd(cur, tab[j]);
			if(cur == 1)
				l = min(l, j - i + 1);
		}
	}
	
	if(l > n)
		puts("-1");
	else
		printf("%d\n", n + l - 2);
	return 0;
}
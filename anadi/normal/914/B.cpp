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
const int INF = 1e9 + 9;

int n, m;
int tab[N];

int main(){
	scanf("%d", &n);
	if(n%2 == 1){
		puts("Conan");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	sort(tab + 1, tab + n + 1);
	
	for(int i = 1; i <= n; i += 2)
		if(tab[i] != tab[i + 1]){
			puts("Conan");
			return 0;
		}
	
	puts("Agasa");
	return 0;
}
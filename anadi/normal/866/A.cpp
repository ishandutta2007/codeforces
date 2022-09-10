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
	
	if(n == 1){
		puts("1 1\n1");
		return 0;
	}
	
	printf("%d %d\n", 2 * n - 2, 2);
	puts("1 2");
	return 0;
}
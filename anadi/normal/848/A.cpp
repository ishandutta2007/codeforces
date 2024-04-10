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

int main(){
	scanf("%d", &n);
	
	if(n == 0){
		puts("a");
		return 0;
	}
	
	char cur = 'a';
	while(n > 0){
		int ile = 2;
		while(ile * (ile + 1) / 2 <= n)
			++ile;
		for(int j = 1; j <= ile; ++j)
			printf("%c", cur);
		n -= ile * (ile - 1) / 2;
		++cur;
	}

	return 0;
}
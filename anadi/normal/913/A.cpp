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
const int INF = 1e9 + 9;

int n, m;
int tab[N];

int main(){
	scanf("%d %d", &m, &n);
	if(m > 30){
		printf("%d\n", n);
		return 0;
	}
	
	int x = 1;
	while(m--)
		x *= 2;
	printf("%d\n", n%x);
	return 0;
}
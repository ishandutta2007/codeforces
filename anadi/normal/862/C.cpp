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
const int X = 1e6;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int tab[N];

int main(){
	scanf("%d %d", &n, &m);
	
	if(n == 1){
		puts("YES");
		printf("%d\n", m);
		return 0;
	}
	
	if(n == 2 && m == 0){
		puts("NO");
		return 0;
	}
	
	if(n == 2){
		puts("YES");
		printf("0 %d\n", m);
		return 0;
	}
	
	puts("YES");
	int last = 1e6;
	while(n > 4){
		n -= 2, last -= 2;
		printf("%d %d ", last, last - 1);
		m ^= last ^ (last - 1);
	}
	
	if(n & 1){
		last -= 2;
		printf("%d %d %d\n", last, last - 1, m ^ last ^ (last - 1));
		return 0;
	}
	
	if(m == 0){
		printf("1 2 4 7");
		return 0;
	}
	
	last -= 2;
	if((last ^ (last - 1)) == m){
		printf("%d %d %d 0\n", last, last - 2, m ^ last ^ (last - 2));
		return 0;
	}
	
	printf("%d %d %d 0\n", last, last - 1, m ^ last ^ (last - 1));
	return 0;
}
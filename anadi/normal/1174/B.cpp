#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];
bool even, odd;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		odd |= in[i] & 1;
		even |= !(in[i] & 1);
	}
	
	if(odd && even)
		sort(in + 1, in + n + 1);
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", in[i]);
	puts("");
	return 0;
}
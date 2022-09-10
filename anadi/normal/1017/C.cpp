#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII  pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;

void write(int from, int to){
	from = max(from, 1);
	for(int i = from; i <= to; ++i)
		printf("%d ", i);
}

int main(){
	scanf("%d", &n);
	int mn = n + 1, opt = 1;
	for(int i = 2; i <= n; ++i)
		if(i + (n + i - 1) / i < mn){
			opt = i;
			mn = i + (n + i - 1) / i;
		}
	
	for(int i = n; i >= 1; i -= opt)
		write(i - opt + 1, i);
	return 0;
}
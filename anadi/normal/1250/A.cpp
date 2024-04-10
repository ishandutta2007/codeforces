#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
char in[N];
int cnt[N];

int main(){
	scanf("%d", &n);
	scanf("%s", in + 1);
	
	for(int i = 1; i <= n; ++i)
		cnt[in[i]]++;
	
	int z = cnt['z'];
	int r = cnt['n'];
	
	while(r--)
		printf("1 ");
	while(z--)
		printf("0 ");
	return 0;
}
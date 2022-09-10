#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int ans[N];
int in[N][N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &in[i][j]);
	
	LL v = 1LL * in[1][2] * in[1][3] / in[2][3];
	int t = sqrt(v);
		
	printf("%d ", t);
	for(int j = 2; j <= n; ++j)
		printf("%d ", in[1][j] / t);
	puts("");
	return 0;
}
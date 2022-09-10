#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 107;
const int T = 1 << 20;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int val1[N];
int val2[N];
int ans[N][N];

int main(){
	cin >> n >> m; int ksor = 0;
	for(int i = 1; i <= n; ++i){
		cin >> val1[i];
		ksor ^= val1[i];
	}

	for(int i = 1; i <= m; ++i){
		cin >> val2[i];
		ksor ^= val2[i];
	}
	
	if(ksor != 0){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	for(int i = 1; i < n; ++i){
		ans[i][1] = val1[i];
		ksor ^= val1[i];
	}
	
	ans[n][1] = ksor ^ val2[1];
	for(int i = 2; i <= m; ++i)
		ans[n][i] = val2[i];
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
	return 0;
}
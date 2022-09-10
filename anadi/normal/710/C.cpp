#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define pb push_back
#define mp make_pair
#define nd second
#define st first

const int N = 1e5 + 7;

int n;
int min_o = 1, min_e = 2;
int dp[100][100];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int ile = min(i - 1, n - i);
		for(int j = n/2 + 1 - ile; j <= n/2 + 1 + ile; ++j)
			dp[i][j] = 1;
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			printf("%d ", dp[i][j] == 0 ? min_e : min_o);
			dp[i][j] == 0 ? min_e += 2 : min_o += 2;
		}
		puts("");
	}
	
	return 0;
}
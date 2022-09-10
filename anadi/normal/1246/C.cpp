#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2007;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m;
char in[N][N];

int canDown[N][N];
int canRight[N][N];

int dpDown[N][N];
int prefDown[N][N];

int dpRight[N][N];
int prefRight[N][N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", in[i] + 1);
	
	for(int i = 1; i <= n; ++i){
		int cnt = 0;
		for(int j = m; j >= 1; --j){
			canRight[i][j] = cnt;
			if(in[i][j] == '.')
				++cnt;
		}		
	}
	
	for(int i = 1; i <= m; ++i){
		int cnt = 0;
		for(int j = n; j >= 1; --j){
			canDown[j][i] = cnt;
			if(in[j][i] == '.')
				++cnt;
		}	
	}
	
	if(in[n][m] == 'R'){
		puts("0");
		exit(0);
	}
	
	for(int i = m; i >= 1; --i){
		if(canRight[n][i] + i == m)
			dpRight[n][i] = 1;
		prefRight[n][i] = dpRight[n][i];
	}

	for(int i = n - 1; i >= 1; --i){
		for(int j = m; j >= 1; --j){
			dpDown[i][j] = (prefRight[i + 1][j] + MX - prefRight[i + canDown[i][j] + 1][j]) % MX;
			prefDown[i][j] = (prefDown[i][j + 1] + dpDown[i][j]) % MX;
			
			dpRight[i][j] = (prefDown[i][j + 1] + MX - prefDown[i][j + canRight[i][j] + 1]) % MX;
			prefRight[i][j] = (prefRight[i + 1][j] + dpRight[i][j]) % MX;
		}
	}
	
	printf("%d\n", (dpRight[1][1] + dpDown[1][1]) % MX);
	return 0;
}
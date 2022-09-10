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
int ans[N][N];
vector <vector <int> > wzo = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};

int main(){
	scanf("%d", &n);
	int dx = 0, dy = 0;
	for(int i = 0; i < n * n; i += 16){
		for(int j = 0; j < 4; ++j)
			for(int k = 0; k < 4; ++k)
				ans[dx + j][dy + k] = i + wzo[j][k];
		
		dy += 4;
		if(dy == n)
			dy = 0, dx += 4;
	}
		
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			printf("%d ", ans[i][j]);
		puts("");
	}

	return 0;
}
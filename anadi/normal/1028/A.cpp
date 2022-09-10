#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 207;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
char s[N][N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			if(s[i][j] == 'W')
				continue;
			
			bool ok = true;
			for(int k = 0; k <= min(i, n - i + 1); ++k)
				if(s[i - k][j] != s[i + k][j] && (s[i - k][j] == 'B' || s[i + k][j] == 'B'))
					ok = false;
			
			for(int k = 0; k <= min(j, m - j + 1); ++k)
				if(s[i][j - k] != s[i][j + k] && (s[i][j - k] == 'B' || s[i][j + k] == 'B'))
					ok = false;
			
			if(ok){
				printf("%d %d\n", i, j);
				return 0;
			}
		}

	return 0;
}
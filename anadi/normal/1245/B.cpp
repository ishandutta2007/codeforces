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

char in[N];
char ans[N];

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--){
		int n, a, b, c;
		scanf("%d %d %d %d", &n, &a, &b, &c);
		scanf("%s", in + 1);
		
		for(int i = 1; i <= n; ++i)
			ans[i] = 0;
		
		int wins = 0;
		for(int i = 1; i <= n; ++i){
			if(in[i] == 'R' && b > 0){
				ans[i] = 'P', b--;
				++wins;
			}

			if(in[i] == 'P' && c > 0){
				ans[i] = 'S', c--;
				++wins;
			}

			if(in[i] == 'S' && a > 0){
				ans[i] = 'R', a--;
				++wins;
			}
		}
		
		for(int i = 1; i <= n; ++i)
			if(ans[i] == 0){
				if(a > 0)
					ans[i] = 'R', a--;
				else if(b > 0)
					ans[i] = 'P', b--;
				else
					ans[i] = 'S', c--;
			}
		
		if(wins >= (n + 1) / 2){
			puts("YES");
			for(int i = 1; i <= n; ++i)
				printf("%c", ans[i]);
			puts("");
		}
		else
			puts("NO");
	}

	return 0;
}
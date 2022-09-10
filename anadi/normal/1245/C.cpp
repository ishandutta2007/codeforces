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
int fib[N];

int main(){
	scanf("%s", in + 1);
	n = strlen(in + 1);
	
	fib[0] = fib[1] = 1;
	for(int i = 2; i <= n; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MX;
	
	int ans = 1;
	for(int i = 1; i <= n; ++i){
		if(in[i] == 'm' || in[i] == 'w'){
			puts("0");
			return 0;
		}
		
		if(in[i] == 'n' || in[i] == 'u'){
			int t = i;
			while(t < n && in[t + 1] == in[i])
				++t;
			
			ans = 1LL * ans * fib[t - i + 1] % MX;
			i = t;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
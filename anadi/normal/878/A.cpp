#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, m;
int dp[20];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 10; ++i)
		dp[i] = 3;

	while(n--){
		char s[2];
		int x;
		scanf("%s %d", s, &x);
		if(s[0] == '^'){
			for(int i = 0; i < 10; ++i)
				if(x & (1 << i))
					dp[i] ^= 1;
		}
		else if(s[0] == '&'){
			for(int i = 0; i < 10; ++i)
				if(!(x & (1 << i)))
					dp[i] = 0;
		}
		else{
			for(int i = 0; i < 10; ++i)
				if(x & (1 << i))
					dp[i] = 1;
		}
	}
	
	int x1 = 0, x2 = 0, x3 = 0;
	for(int i = 0; i < 10; ++i){
		if(dp[i] != 0)
			x2 += 1 << i;
		if(dp[i] == 2)
			x1 += 1 << i;
		if(dp[i] == 1)
			x3 += 1 << i; 
	}
	
	printf("3\n^ %d\n& %d\n| %d\n", x1, x2, x3);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define pb push_back

double ile[15][15];
bool use[15][15];

int main(){
	int n, t;
	scanf("%d %d", &n, &t);
	if(t == 0){
		puts("0");
		return 0;
	}
	if(t < 3 || n == 1){
		puts("1");
		return 0;
	}
	
	int res = 0;
	for(int i = 1; i <= t; ++i){
		ile[1][1] += 1.0;
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= j; ++k){
				if(ile[j][k] > 1.0){
					ile[j + 1][k] += (ile[j][k] - 1)/2.0;
					ile[j + 1][k + 1] += (ile[j][k] - 1)/2.0;
					ile[j][k] = 1.0;
				}
				
				if(!use[j][k] && ile[j][k] >= 1.0){
					++res;
					use[j][k] = true;
				}
			}
	}
	
	printf("%d\n", res);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 19LL;

int n;
char s[N];
int x[N], y[N];

int main(){
	scanf("%d %s", &n, s + 2); int res = 0;
	for(int i = 2; i <= n + 1; ++i){
		x[i] = x[i - 1] + (s[i] == 'U');
		y[i] = y[i - 1] + (s[i] == 'R');
		
		if(x[i] > y[i] && x[i - 2] < y[i - 2])
			++res;
		if(x[i] < y[i] && x[i - 2] > y[i - 2])
			++res;
	}
	
	printf("%d\n", res);
	return 0;
}
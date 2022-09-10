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
const LL INF = 1e18 + 9LL;

int n, d;
int x[N];

int main(){
	scanf("%d %d", &n, &d);
	int res = 2;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	
	for(int i = 2; i <= n; ++i)
		if(x[i] - x[i - 1] == d + d)
			++res;
		else
			if(x[i] - x[i - 1] > d + d)
				res += 2;
	
	printf("%d\n", res);
	return 0;
}
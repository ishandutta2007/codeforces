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

int n;
int res;
int in[N];

int main(){
	scanf("%d", &n); in[n + 1] = 1001;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);

	for(int i = 0; i <= n; ++i){
		int wsk = i;
		while(wsk <= n && in[wsk + 1] == in[wsk] + 1)
			++wsk;
		
		res = max(res, wsk - i - 1);
	}
	
	printf("%d\n", res);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n + n; ++i)
		scanf("%d", &in[i]);
	sort(in + 1, in + n + n + 1);
	
	if(in[1] < in[n + n]){
		for(int i = 1; i <= n + n; ++i)
			printf("%d ", in[i]);
	}
	else
		puts("-1");
	return 0;
}
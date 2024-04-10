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
int in[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	sort(in + 1, in + n + 1);

	if(n == 1){
		printf("%d\n", in[1]);
		return 0;
	}

	LL res = -in[1] + in[n];
	for(int i = 2; i < n; ++i)
		res += abs(in[i]);
	printf("%lld\n", res);
	return 0;
}
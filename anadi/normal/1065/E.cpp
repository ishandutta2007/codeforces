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
const int MX = 998244353;
const LL INF = 1e18 + 9LL;

int n, m, A;
int in[N];

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a)%MX;
		
		b >>= 1;
		a = (1LL * a * a)%MX;
	}
	
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &m, &A);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &in[i]);
	
	int res = fast(A, n - 2 * in[m]), odw = (MX + 1) / 2;
	for(int i = 1; i <= m; ++i){
		int t = in[i] - in[i - 1];

		int cur = fast(A, t + t) + fast(A, t);
		cur = (1LL * cur * odw)%MX;		
		res = (1LL * res * cur)%MX;
	}

	printf("%d\n", res);
	return 0;
}
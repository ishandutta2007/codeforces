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

int n;
int sil[N];
int odw[N];

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

int newton(int a, int b){
	return (((1LL * sil[a] * odw[b])%MX) * odw[a - b])%MX;
}

int main(){
	scanf("%d", &n); sil[0] = 1;
	for(int i = 1; i <= n; ++i)
		sil[i] = (1LL * sil[i - 1] * i)%MX;
	
	odw[n] = fast(sil[n], MX - 2);
	for(int i = n; i >= 1; --i)
		odw[i - 1] = (1LL * i * odw[i])%MX;
	
	LL res = sil[n];
	for(int i = 1; i < n; ++i)
		res += (((1LL * sil[i] * (sil[n - i] - 1))%MX) * newton(n, i))%MX;
	printf("%lld\n", res%MX);
	return 0;
}
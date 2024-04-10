#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 998244353;
const LL INF = 1e18 + 9LL;

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a)%MX;
		
		a = (1LL * a * a)%MX;
		b >>= 1;
	}
	
	return ret;
}

int n;
int sil[N];
int odw[N];
LL res = 0LL;

int symbol(int a, int b){
	if(b < 0 || a < b || a < 0)
		return 0;
	return (((1LL * sil[a] * odw[b])%MX) * odw[a - b])%MX;
}

int main(){
	scanf("%d", &n);
	if(n == 1){
		puts("3");
		return 0;
	}
	
	sil[0] = 1;
	for(int i = 1; i <= n; ++i)
		sil[i] = (1LL * sil[i - 1] * i)%MX;
	
	odw[n] = fast(sil[n], MX - 2);
	for(int i = n - 1; i >= 0; --i)
		odw[i] = (1LL * odw[i + 1] * (i + 1))%MX;
	
	int pt3 = fast(3, n);
	for(int i = 1; i <= n; ++i)
		res += (3LL * fast((pt3 + MX - 3)%MX, i - 1)%MX * fast(pt3, n - i))%MX;
	res %= MX;

	for(int i = 1; i <= n; ++i){
		LL cur = ((1LL * ((fast(3, i) + MX - 3)%MX) * fast(pt3, n - i))%MX + (3LL * fast(fast(3, n - i) - 1, n))%MX)%MX;
		cur = (1LL * cur * symbol(n, i))%MX;
//		printf("%lld\n", cur%MX);
		if(i%2 == 0)
			cur = MX - cur;
		res += cur;
	}

	printf("%lld\n", res%MX);
	return 0;
}
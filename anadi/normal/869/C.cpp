#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const LL MX = 998244353LL;

int a, b, c;
LL sil[N];
LL odw[N];

LL fast(LL a, LL b){
	if(b == 0)
		return 1LL;
	LL x = fast(a, b / 2LL);
	if(b & 1)
		return (((x * x)%MX) * a)%MX;
	return (x * x)%MX;
}

LL newton(LL a, LL b){
	if(b < 0 || a < b)
		return 0LL;
	return (((sil[a] * odw[b])%MX) * odw[a - b])%MX;
}

LL solve(LL x, LL y){
	LL cur = 0LL;
	for(int i = 0; i <= min(x, y); ++i)
		cur = (cur + (((newton(x, i) * newton(y, i))%MX) * sil[i])%MX)%MX;
	return cur;
}

int main(){
	scanf("%d %d %d", &a, &b, &c);
	
	sil[0] = 1LL;
	odw[0] = 1LL;
	for(int i = 1; i < N; ++i){
		sil[i] = (1LL * sil[i - 1] * i)%MX;
		odw[i] = fast(sil[i], MX - 2);
	}
	
	LL res = (((solve(a, b) * solve(a, c))%MX) * solve(b, c))%MX;
	printf("%lld\n", res);
	return 0;
}
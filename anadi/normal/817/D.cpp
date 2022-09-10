#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int N = 1e6 + 7;

int n, K;
int mx[3 * N];
int zro[3 * N];
int tab[N];
LL res = 0LL;

void construct(){
	K = 1;
	while(K < n)
		K *= 2;

	for(int i = 1; i <= n; ++i)
		mx[K + i - 1] = tab[i],
		zro[K + i - 1] = i;
	for(int i = K - 1; i >= 1; --i)
		mx[i] = max(mx[2 * i], mx[2 * i + 1]),
		zro[i] = mx[2 * i] > mx[2 * i + 1] ? zro[2 * i] : zro[2 * i + 1];
}

int ask(int p, int k){
	p += K - 1;
	k += K - 1;
	int ret = p;
	while(p < k){
		if((p & 1) && mx[p] > mx[ret])
			ret = p;
		if(!(k & 1) && mx[k] > mx[ret])
			ret = k;
		p = (p + 1) >> 1;
		k = (k - 1) >> 1;
	}
	
	if(p == k && mx[p] > mx[ret])
		ret = k;
	return zro[ret];
}

void solve(int p, int k){
	if(p > k)	return;
	int now = ask(p, k);
	res += 1LL * tab[now] * (k - now + 1) * (now - p + 1);
	solve(p, now - 1);
	solve(now + 1, k);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	
	construct();
	solve(1, n);
	for(int i = 1; i <= n; ++i)
		tab[i] *= -1;
	construct();
	solve(1, n);
	printf("%lld\n", res);
	return 0;
}
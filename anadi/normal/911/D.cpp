#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, K;
int tab[N];
int tree[N];

void add(int x){
	x += K;
	tree[x] = 1;
	
	while(x > 1){
		x /= 2;
		tree[x] = tree[x + x] + tree[x + x + 1];
	}
}

int ile(int p, int k){
	int res = 0;
	p += K, k += K;
	
	while(p < k){
		if(p & 1)
			res += tree[p];
		if(!(k & 1))
			res += tree[k];
		
		p = (p + 1) >> 1;
		k = (k - 1) >> 1;
	}
	
	if(p == k)
		res += tree[p];
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	
	K = 1;
	while(K < n)
		K *= 2;
	--K;
	
	int cur = 0;
	for(int i = 1; i <= n; ++i){
		cur += ile(tab[i] + 1, n);
		add(tab[i]);
		cur &= 1;
	}
	
	int q; scanf("%d", &q);
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);
		long long int l = b - a + 1;
		
		l = l * (l - 1) / 2LL;
		cur ^= (l & 1);
		if(cur)
			puts("odd");
		else
			puts("even");
	}

	return 0;
}
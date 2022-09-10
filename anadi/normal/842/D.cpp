#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int K = 1 << 19;
const int N = 2 * K + 7;

const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, q;
bool tree[N];

int ask(int cur){
	int x = 1, res = 0, roz = 18;
	while(x < K){
		int lewy = x + x, prawy = x + x + 1;
		if(cur & (1 << roz))
			swap(lewy, prawy);
		
		if(tree[lewy])
			x = prawy,
			res += (1 << roz);
		else
			x = lewy;
		roz--;
	}
	
	if(tree[x])
		res += roz;
	return res;
}

int main(){
	scanf("%d %d", &n, &q);	
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		tree[x + K] = true;
	}
	
	for(int i = K - 1; i >= 1; --i)
		tree[i] = tree[i + i] && tree[i + i + 1];
	
	int cur = 0;
	while(q--){
		int x;
		scanf("%d", &x);
		cur ^= x;
		printf("%d\n", ask(cur));
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int V = 62;
const int N = 1e6 + 7;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
LL k, ret;

LL ini[N];
LL masks[N];

void solve(LL bg, int nr){
	LL cnt = 0LL;
	int p = 1, e = 1;
	for(int i = 1; i <= n; ++i){
		while(e <= n && (masks[e] & bg) <= (ini[i] & bg))
			++e;
		while(p <= n && (masks[p] & bg) < (ini[i] & bg))
			++p;
		
		cnt += e - p;
	}
	
	if(cnt < k){
		for(int i = 1; i <= n; ++i){
			int wsk = i;
			while(wsk < n && (masks[wsk + 1] & bg) == (masks[wsk] & bg))
				++wsk;
			
			if(masks[wsk] & (1LL << nr)){
				i = wsk;
				continue;
			}
			
			int wsk2 = wsk + 1;
			if(wsk2 > n || ((masks[wsk2] & bg) - (1LL << nr)) != (masks[wsk] & bg)){
				i = wsk;
				continue;
			}
			
			while(wsk2 < n && (masks[wsk2 + 1] & bg) == (masks[wsk2] & bg))
				++wsk2;
			
			reverse(masks + i, masks + wsk + 1);
			reverse(masks + wsk + 1, masks + wsk2 + 1);
			reverse(masks + i, masks + wsk2 + 1);
			i = wsk2;
		}
		
		for(int i = 1; i <= n; ++i)
			masks[i] ^= 1LL << nr;
		
		k -= cnt;
		ret += 1LL << nr;
	}
	
//	for(int i = 1; i <= n; ++i)
//		printf("%lld %lld\n", ini[i], masks[i]);
//	puts("");
}

int main(){
	scanf("%d %lld", &n, &k);
	for(int i = 2; i <= n; ++i){
		int p; LL w;
		scanf("%d %lld", &p, &w);
		masks[i] = masks[p] ^ w;
	}
	
	sort(masks + 1, masks + n + 1);
	for(int i = 1; i <= n; ++i)
		ini[i] = masks[i];

	for(int i = V - 1; i >= 0; --i)
		solve((1LL << V) - (1LL << i), i);
	
	printf("%lld\n", ret);
	return 0;
}
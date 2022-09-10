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
char t[N];
LL dist[N];

LL ans = 0LL;
LL Water, Grass;
bool water, grass;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &dist[i]);
		ans += dist[i];
		dist[i] *= 2;
	}
	
	scanf("%s", t + 1);
	for(int i = 1; i <= n; ++i){
		if(t[i] == 'G'){
			grass = true;
			LL Fly = min(dist[i], 2 * Water);
			Water -= Fly / 2;
			
			ans += Fly / 2;
			Grass += Fly + (dist[i] - Fly) / 2;
			ans += dist[i] - Fly;
		}
		else if(t[i] == 'W'){
			water = true;
			Water += dist[i] / 2;
			ans += dist[i] / 2;
		}
		else{
			LL cntW = min(dist[i], 2 * Water);
			Water -= cntW / 2;
			ans += cntW / 2;
			
			LL cntG = min(dist[i] - cntW, 2 * Grass);
			Grass -= cntG / 2;
			ans += cntG;
			
			if(cntW + cntG < dist[i])
				ans += water ? 3 * (dist[i] - cntW - cntG) / 2 : 5 * (dist[i] - cntW - cntG) / 2;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}
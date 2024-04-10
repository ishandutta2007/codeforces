#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int q;
LL pot[100];
LL node[100];
LL shift[100];

int level(LL x){
	int ans = 0;
	while(x > 1)
		++ans, x /= 2;
	return ans;
}

void recover(LL x, int t){
	if(t == 0){
		puts("1");
		return;
	}
	
//	printf("JESTEM W %lld %d\n", x, t);
	LL y = x - pot[t];
	y += shift[t];
	y %= pot[t];
	y += pot[t];
	printf("%lld ", y);

	x -= pot[t];
	x += node[t];
	x %= pot[t];
	x += pot[t];
	recover(x / 2, t - 1);
}

int main(){
	pot[0] = 1;
	for(int i = 1; i < 61; ++i)
		pot[i] = pot[i - 1] + pot[i - 1];

	scanf("%d", &q);
	while(q--){
		int t;
		LL x, k;
		scanf("%d %lld", &t, &x);
		
		if(t == 3){
			if(x == 1){
				puts("1");
				continue;
			}

			printf("%lld ", x); int t = level(x);
			x -= pot[t]; x += pot[t] - shift[t] + node[t];
			x %= pot[t]; x += pot[t];
			recover(x / 2, level(x) - 1);
			continue;
		}
		
		scanf("%lld", &k);
		if(t == 2){
			int u = level(x);
			node[u] = (((node[u] + k)%pot[u]) + pot[u])%pot[u];
		}
		else{
			int u = level(x);
			shift[u] = (((shift[u] - k)%pot[u]) + pot[u])%pot[u];
		}
	}

	return 0;
}
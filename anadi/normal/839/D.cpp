#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e6;
const int inf  = 1e9 + 7;

int n;
int ile[N];
int res[N];
int pot[N];
int spec[N];

inline int mod(int x){
	if(x >= inf)
		x -= inf;
	return x;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		ile[a]++;
	}

	pot[0] = 1LL;
	for(int i = 1; i <= n; ++i)
		pot[i] = mod(2 * pot[i - 1]),
		spec[i] = mod(mod(2 * spec[i - 1]) + pot[i - 1]);
	
	LL global = 0LL;
	for(int i = MX; i >= 2; --i){
		int now = 0;
		for(int j = i; j <= MX; j += i)
			res[i] = (res[i] - res[j])%inf,
			now += ile[j];
		
		res[i] = (res[i] + spec[now])%inf;
		global = (global + 1LL * i * res[i])%inf;
	}
	
	global = (global + inf)%inf;
	printf("%lld\n", global);
	return 0;
}
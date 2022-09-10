#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

int n, k;
int c[100007];
bool cap[100007];
LL res = 0LL;
LL suma = 0LL;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &c[i]);
		suma += c[i];
	}
	
	LL min = 0LL;
	for(int i = 1; i <= k; ++i){
		int a;
		scanf("%d", &a);
		min += c[a];
		res += c[a] * (suma - min);
		cap[a] = true;
	}
	
	for(int i = 1; i <= n; ++i){
		if(cap[i])
			continue;
		if(cap[i + 1])
			continue;
		res += c[i] * c[i + 1];
	}
	
	if(!cap[1] && !cap[n])
		res += c[1] * c[n];
	printf("%I64d\n", res);
	return 0;
}
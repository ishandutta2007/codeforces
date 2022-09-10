#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int inf = 1e9 + 7;
const D eps = 1e-5;

int n, P;
int p[N], s[N];
long long int sum = 0;

bool ok(D czas){
	double need = 0.0;
	for(int i = 1; i <= n; ++i)
		need += max(p[i] * czas - s[i], 0.0);
	return need <= D(czas * P);
}

D BS(D p, D k){
	while(k - p > eps){
		D m = (p + k) / 2.0;
		if(ok(m))
			p = m;
		else
			k = m;
	}
	
	return p;
}

int main(){
	scanf("%d %d", &n, &P);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &p[i], &s[i]);
		sum += p[i];
	}
	
	if(sum <= P){
		puts("-1");
		return 0;
	}
	
	printf("%.4lf\n", BS(0, 10LL * inf));
	return 0;
}
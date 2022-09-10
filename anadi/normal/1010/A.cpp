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

int n, m;
int a[N], b[N];

bool ok(double mass){
	mass -= mass / a[1];
	for(int i = 2; i <= n; ++i){
		mass -= mass / b[i];
		mass -= mass / a[i];
	}
	
	mass -= mass / b[1];
	return m <= mass;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		if(a[i] == 1){
			puts("-1");
			return 0;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", &b[i]);
		if(b[i] == 1){
			puts("-1");
			return 0;
		}
	}
	
	int turns = 300;
	double p = 0.0, k = 1e9;
	while(turns--){
		double mid = (p + k) / 2.0;
		if(ok(mid + m))
			k = mid;
		else
			p = mid;
	}
	
	printf("%.9lf\n", (p + k) / 2.0);
	return 0;
}
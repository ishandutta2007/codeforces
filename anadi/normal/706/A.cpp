#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define pb push_back
#define mp make_pair
#define PII pair <int, int>
#define st first
#define nd second
#define PLL pair <LL, LL>
#define PDD pair <D, D>

const int N = 1;

D odl(D x, D y){
	return sqrt(x * x + y * y);
}

int main(){
	D a, b;
	scanf("%lf %lf", &a, &b);
	int n;
	scanf("%d", &n);
	
	double res = 1e9;
	for(int i = 1; i <= n; ++i){
		double x, y, v;
		scanf("%lf %lf %lf", &x, &y, &v);
		res = min(res, odl(x - a, y - b) / v);
	}
	
	printf("%.6lf\n", res);
	return 0;
}
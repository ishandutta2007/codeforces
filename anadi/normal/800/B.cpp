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

int n;
int x[N], y[N];

double f(int p, int a, int b){
	if(p == a || p == b | a == b)
		return D(inf);
	
	double A, B, C;
	if(x[a] == x[b]){
		A = 1.0;
		B = 0.0;
		C = -x[a];
	}
	else{
		A = y[b] - y[a];
		B = x[a] - x[b];
		C = -1.0 * x[a] * y[b] + 1.0 * x[b] * y[a];
	}
	
	return abs(A * x[p] + B * y[p] + C) / sqrt(A * A + B * B) / 2.0;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &x[i], &y[i]);
	
	double res = 2.0 * D(inf);
	for(int i = 0; i < n; ++i){
		int ch = (i + n - 1)%n;
		for(int j = 0; j < n; ++j)
			res = min(res, f(i, ch, j));
		
		ch = (i + 1)%n;
		for(int j = 0; j < n; ++j)
			res = min(res, f(i, ch, j));
	}
	
	printf("%.6lf\n", res);
	return 0;
}
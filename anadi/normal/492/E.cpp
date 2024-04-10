#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair

const int mxn = 1e6 + 7;

int T[mxn];
int X[mxn];

int main(){
	LL n, m;
	LL dx, dy;
	scanf("%I64d %I64d", &n, &m);
	scanf("%I64d %I64d", &dx, &dy);
	
	int now = 1;
	for(int i = 0; i <= n; ++i){
		X[now] = i;
		now -= dx;
		now %= n;
		now += n;
		now %= n;
	}
		
	int result = 0;
	PLL res;
	for(int i = 1; i <= m; ++i){
		LL x, y;
		scanf("%I64d %I64d", &x, &y);
		LL XD = x;
		LL Y = y;
		y += (1LL * (LL)X[x] * dy)%n;
		y %= n;
		y += n;
		y %= n;
		T[y]++;
		if(T[y] > result){
			result = T[y];
			res = mp(XD, Y);
		}
	}
	
	printf("%I64d %I64d\n", res.st, res.nd);
	return 0;
}
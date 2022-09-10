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
const LL INF = 1e18 + 19LL;

LL r, x1, x2, YY, y2;

LL kwa(LL a){
	return a * a;
}

int main(){
	scanf("%lld %lld %lld %lld %lld", &r, &x1, &YY, &x2, &y2);
	
	if(kwa(x2 - x1) + kwa(y2 - YY) > r * r){
		printf("%lld %lld %lld\n", x1, YY, r);
		return 0;
	}
	
	if(x1 == x2){
		D rr = 1.0 * (abs(YY - y2) + r) / 2.0, y;
		if(YY > y2)
			y = YY - D(YY - y2) / 2.0 + D(r) / 2.0;
		else
			y = YY + D(y2 - YY) / 2.0 - D(r) / 2.0;
		printf("%lld %.9lf %.9lf\n", x1, y, rr);
		return 0;
	}
	
	D a = D(YY - y2) / D(x1 - x2);
	D R = D(sqrt(kwa(x2 - x1) + kwa(y2 - YY)) + r) / 2.0;

	D x = sqrt(R * R / (1.0 + a * a));
	D y = abs(a * x);
	
	if(x1 < x2)
		x = x2 - x;
	else
		x = x2 + x;
	
	if(YY < y2)
		y = y2 - y;
	else
		y = y2 + y;
	printf("%.9lf %.9lf %.9lf\n", x, y, R);
	return 0;
}
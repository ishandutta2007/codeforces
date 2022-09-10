#include <bits/stdc++.h>

using namespace std;

typedef long double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

D a, b, c;
D xa, ya, xb, yb;

D kwa(D x){
	return x * x;
}

D dist(D xf, D yf, D xt, D yt){
	return sqrt(kwa(xf - xt) + kwa(yf - yt));
}

int main(){
	cin >> a >> b >> c;
	cin >> xa >> ya >> xb >> yb;
	
	D res = abs(xa - xb) + abs(ya - yb);
	if(a == 0 || b == 0){
		printf("%.9Lf\n", res);
		return 0;
	}
	
	D valay = (-c - xa * a) / b;
	D valax = (-c - ya * b) / a;
	
	D valby = (-c - xb * a) / b;
	D valbx = (-c - yb * b) / a;
	
	res = min(res, abs(ya - valay) + abs(yb - valby) + dist(xa, valay, xb, valby));
	res = min(res, abs(xa - valax) + abs(yb - valby) + dist(valax, ya, xb, valby));
	res = min(res, abs(ya - valay) + abs(xb - valbx) + dist(xa, valay, valbx, yb));
	res = min(res, abs(xa - valax) + abs(xb - valbx) + dist(valax, ya, valbx, yb));
	printf("%.9Lf\n", res);	
	return 0;
}
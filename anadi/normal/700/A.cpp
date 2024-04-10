#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const LL MX = 1e9 + 7LL;
const LD eps = 1e-9;
const int mxn = 1e5 + 7;

int n, v1, v2, l, k;

int main(){
	scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);	
	int g = (n + k - 1) / k;
	LD l1 = ((LD)l) * ((LD)(v1 + v2));
	l1 /= 2.0 * ((LD)v1) * ((LD)g) - ((LD)v1) + ((LD)v2);
	LD t = l1 / ((LD)v2);
	LD l2 = l - l1;
	t += l2 / ((LD)v1);
	printf("%.6lf\n", t);
	return 0;
}
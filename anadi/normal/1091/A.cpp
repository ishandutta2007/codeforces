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

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int r = min(a, min(b - 1, c - 2));
	printf("%d\n", 3 * r + 3);
	return 0;
}
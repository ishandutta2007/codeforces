#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, a, b;

int main(){
	scanf("%d %d %d", &n, &a, &b);
	int res = 1;
	while(a / (res + 1) + b / (res + 1) >= n && res + 1 <= a && res + 1 <= b)
		++res;
	printf("%d\n", res);
	return 0;
}
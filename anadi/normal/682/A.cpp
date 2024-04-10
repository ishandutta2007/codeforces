#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLD pair <LD, LD>
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int N = 1e5 + 9;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	LL result = 0LL;
	result += 1LL * (n / 5) * (m / 5);
	result += 1LL * ((n + 1) / 5) * ((m + 4) / 5);
	result += 1LL * ((n + 2) / 5) * ((m + 3) / 5);
	result += 1LL * ((n + 3) / 5) * ((m + 2) / 5);
	result += 1LL * ((n + 4) / 5) * ((m + 1) / 5);
	printf("%I64d\n", result);
	return 0;
}
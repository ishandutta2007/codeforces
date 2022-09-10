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

int n;
int t[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	sort(t + 1, t + n + 1);
	
	int mn = 1;
	for(int i = 1; i <= n; ++i)
		if(t[i] >= mn)
			++mn;
	printf("%d\n", mn);
	return 0;
}
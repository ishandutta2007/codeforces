#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define pb push_back
#define mp make_pair
#define nd second
#define st first

const int N = 3e5 + 7;

int n;
int T[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &T[i]);
	
	sort(T + 1, T + n + 1);
	++n;
	n /= 2;
	
	printf("%d\n", T[n]);
	return 0;
}
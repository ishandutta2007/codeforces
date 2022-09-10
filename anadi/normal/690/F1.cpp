#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int N = 1e4 + 7;

int n;
int roz[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		roz[a]++;
		roz[b]++;
	}
	
	int result = 0;
	for(int i = 1; i <= n; ++i)
		result += (roz[i] - 1) * roz[i] / 2;
	printf("%d\n", result);
	return 0;
}
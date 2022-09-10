#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int a[N];
PII b[N];
int res[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &b[i].st);
		b[i].nd = i;
	}
	
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	
	for(int i = n; i >= 1; --i)
		res[b[n - i + 1].nd] = a[i];
	for(int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	return 0;
}
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
const LL IxNF = 1e18 + 9LL;

int n, m; LL s;
int a[N], b[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]),
		s += a[i];

	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &b[i]),
		s -= b[i];
	
	if(s != 0){
		puts("-1");
		return 0;
	}
	
	LL sa = 0, sb = 0;
	int res = 0, ca = 0, cb = 0;
	
	while(ca < n || cb < m){
		if(sa < sb)
			sa += a[++ca];
		else if(sb < sa)
			sb += b[++cb];
		else if(sa == sb){
			++res;
			sa = a[++ca], sb = b[++cb];
		}
	}
	
	printf("%d\n", res);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, p;
int pref[N], suf[N];

int main(){
	scanf("%d %d", &n, &p);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &pref[i]);
		suf[i] = pref[i];
		pref[i] = (pref[i] + pref[i - 1])%p;
	}
	
	for(int i = n; i >= 1; --i)
		suf[i] = (suf[i] + suf[i + 1])%p;
	
	int res = 0;
	for(int i = 1; i < n; ++i)
		res = max(res, (pref[i]%p) + (suf[i + 1]%p));
	printf("%d\n", res);
	return 0;
}
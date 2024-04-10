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

int n, q;
char s[N];
int pt[N];
int pref[N][2];

int main(){
	scanf("%d %d", &n, &q);
	scanf("%s", s + 1);

	pt[0] = 1;
	for(int i = 1; i <= n; ++i){
		pt[i] = (pt[i - 1] + pt[i - 1])%MX;
		pref[i][0] = pref[i - 1][0] + (s[i] == '0');
		pref[i][1] = pref[i - 1][1] + (s[i] == '1');
	}
	
	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);
		
		int cnt0 = pref[r][0] - pref[l - 1][0];
		int cnt1 = pref[r][1] - pref[l - 1][1];
		
		printf("%lld\n", (1LL * pt[cnt0] * (pt[cnt1] - 1))%MX);
	}

	return 0;
}
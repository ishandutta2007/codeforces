#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int T = 1 << 20;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, q;
int pref[N];
char s1[N], s2[N];

bool ok(int p){
	--p;
	for(int i = 1; i <= m; ++i)
		if(s1[i + p] != s2[i])
			return false;
	return true;
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	scanf("%s %s", s1 + 1, s2 + 1);
	
	for(int i = 1; i <= n - m + 1; ++i){
		pref[i] = pref[i - 1];
		if(ok(i))
			pref[i]++;
	}
	
	while(q--){
		int from, to;
		scanf("%d %d", &from, &to);
		
		if(to - from + 1 < m)
			puts("0");
		else
			printf("%d\n", pref[to - m + 1] - pref[from - 1]);
	}

	return 0;
}
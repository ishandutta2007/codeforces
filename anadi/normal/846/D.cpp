#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 507;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, m;
int k, q;
bool use[N][N];
int pref[N][N];
pair <int, PII> quest[N * N];

bool ok(int ile){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			use[i][j] = false;
	
	for(int i = 1; i <= ile; ++i)
		use[quest[i].nd.st][quest[i].nd.nd] = true;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + use[i][j];
	
	for(int i = k; i <= n; ++i)
		for(int j = k; j <= m; ++j)
			if((pref[i][j] - pref[i - k][j] - pref[i][j - k] + pref[i - k][j - k]) == k * k)
				return false;
	return true;
}

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i = 1; i <= q; ++i)
		scanf("%d %d %d", &quest[i].nd.st, &quest[i].nd.nd, &quest[i].st);
	sort(quest + 1, quest + q + 1);
	
	if(ok(q)){
		puts("-1");
		return 0;
	}
	
	int p = 1, e = q;
	while(p < e){
		int m = (p + e) >> 1;
		if(ok(m))
			p = m + 1;
		else
			e = m;
	}
	
	printf("%d\n", quest[p].st);
	return 0;
}
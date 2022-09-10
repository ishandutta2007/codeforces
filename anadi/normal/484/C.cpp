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

int n, m;
int k, d;
char s[N];
char help[N];
int perm[N + N];
int jump[N + N][20];

bool cmp(int a, int b){
	if(a%d == b%d)
		return a < b;
	return a%d < b%d;
}

void solve(){
	scanf("%d %d", &k, &d);
	for(int i = 0; i < k; ++i)
		perm[i + n - k + 1] = i;
	sort(perm + n - k + 1, perm + n + 1, cmp);
	
	for(int i = 0; i < k; ++i)
		perm[i + n - k + 1] += n - k + 1;
	
	for(int i = 0; i < k; ++i)
		jump[perm[i + n - k + 1]][0] = i + n - k + 1;
	for(int i = 0; i < k; ++i)
		perm[i + n - k + 1] = jump[i + n - k + 1][0] - 1;
	
	for(int i = 1; i <= n - k; ++i)
		perm[i] = i - 1;
	for(int i = 0; i < n - k; ++i)
		perm[n + i + 1] = n + i;
	
//	for(int i = 0; i <= n + n - k; ++i)
//		printf("%d ", perm[i]);
//	puts("");

	for(int i = 1; i <= n + n - k; ++i)
		jump[perm[i]][0] = i;
	
	for(int i = 1; i < 20; ++i)
		for(int j = 0; j <= n + n - k; ++j)
			jump[j][i] = jump[jump[j][i - 1]][i - 1];
	
	for(int i = 0; i < n; ++i){
		perm[i] = i;
		for(int j = 0; j < 20; ++j)
			if((n - k + 1) & (1 << j))
				perm[i] = jump[perm[i]][j];
		
		perm[i] -= n - k + 1;
		help[i] = s[perm[i]];
	}
	
	for(int i = 0; i < n; ++i)
		s[i] = help[i];
	printf("%s\n", s);
}

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	scanf("%d", &m);
	while(m--)
		solve();
	return 0;
}
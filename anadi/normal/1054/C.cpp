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

int n;
int res[N];
int l[N], r[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &l[i]);
	for(int j = 1; j <= n; ++j)
		scanf("%d", &r[j]);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(l[j] + r[j] > l[i] + r[i])
				res[i]++;
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j)
			if(res[j] > res[i])
				--l[i];

		for(int j = i + 1; j <= n; ++j)
			if(res[j] > res[i])
				--r[i];
		
		if(l[i] != 0 || r[i] != 0){
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");
	for(int i = 1; i <= n; ++i)
		printf("%d ", res[i] + 1);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double LD;
typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define pb push_back
#define PLL pair <LL, LL>
#define pb push_back

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7LL;
const int mxn = 2e5 + 7;

char s[mxn];
int t[mxn];
int result = INF;

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	for(int i = 2; i <= n; ++i)
		if(s[i] == 'L' && s[i - 1] == 'R')
			result = min(result, (t[i] - t[i - 1])/2);
	
	result == INF ? puts("-1") : printf("%d\n", result);
	return 0;
}
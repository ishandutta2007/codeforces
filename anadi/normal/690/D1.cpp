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

const int N = 1e3 + 7;

int n, m;
char s[N];
int result = 0;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; ++i)
		scanf("%s", s);
	scanf("%s", s + 1);
	
	if(s[1] == 'B')
		++result;
	
	for(int i = 2; i <= m; ++i)
		if(s[i] != s[i - 1] && s[i] == 'B')
			++result;
	printf("%d\n", result);
	return 0;
}
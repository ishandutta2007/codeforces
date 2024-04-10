#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define PLL pair <LL, LL>
#define PDD pair <D, D>

const int N = 1e5 + 7;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	bool res = false;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			char s;
			scanf(" %c", &s);
			if(s == 'C' || s == 'M' || s == 'Y')
				res = true;
		}
	}
	
	if(res)
		puts("#Color");
	else
		puts("#Black&White");
	return 0;
}
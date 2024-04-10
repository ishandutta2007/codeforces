#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
char s[N];
int close, open;

void nie(){
	puts("No");
	exit(0);
}

bool check(int from, int to){
	int cur = 0;
	for(int i = from; i <= to; ++i){
		if(s[i] == 'x')	continue;
		if(s[i] == ')')
			--cur;
		if(s[i] == '(')
			++cur;
		
		if(cur < 0)
			return false;
	}
	
	return cur == 0;
}

int main(){
	scanf("%d %s", &n, s + 1);
	for(int i = 1; i <= n; ++i){
		if(s[i] == ')' && close == 0)
			close = i;
		if(s[i] == '(')
			open = i;
	}
	
	if(open == 0 || close == 0)
		nie();
	
	s[close] = 'x';
	s[n + 1] = ')';
	
	if(check(1, n + 1)){
		puts("Yes");
		return 0;
	}
	
	s[close] = ')';
	s[open] = 'x';
	s[0] = '(';
	
	if(check(0, n))
		puts("Yes");
	else
		nie();
	return 0;
}
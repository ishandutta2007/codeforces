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
char s[N];

int main(){
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	
	m /= 2;
	int cnt = 0, cnt2 = 0;
	for(int i = 1; i <= n; ++i){
		if(s[i] == '(' && cnt < m){
			printf("(");
			++cnt;
		}

		if(s[i] == ')' && cnt2 < cnt){
			printf(")");
			++cnt2;
		}
	}

	return 0;
}
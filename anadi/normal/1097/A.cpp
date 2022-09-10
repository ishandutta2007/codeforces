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

char s[5];
char in[5];

int main(){
	scanf("%s", s);
	for(int i = 0; i < 5; ++i){
		scanf("%s", in);
		if(in[0] == s[0] || in[1] == s[1]){
			puts("YES");
			return 0;
		}
	}
	
	puts("NO");
	return 0;
}
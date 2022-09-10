#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define pb push_back
#define mp make_pair
#define nd second
#define st first

const int N = 1e5 + 7;

int main(){
	char s[2];
	scanf("%s", s);
	
	int r = 4;
	if((s[0] == 'a' || s[0] == 'h') && (s[1] == '1' || s[1] == '8')){
		puts("3");
		return 0;
	}

	if(s[1] == '1' || s[1] == '8' || s[0] == 'a' || s[0] == 'h'){
		puts("5");
		return 0;
	}
	
	puts("8");
	return 0;
}
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
const LL INF = 1e18 + 19LL;

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	if(y == 0){
		puts("No");
		return 0;
	}
	
	if(x == 0 && y == 1){
		puts("Yes");
		return 0;
	}
	
	if(x > 0 && y == 1){
		puts("No");
		return 0;
	}
	
	if(x + 1 < y){
		puts("No");
		return 0;
	}
	
	--y;
	if((x - y)%2 == 0)
		puts("Yes");
	else
		puts("No");
	return 0;
}
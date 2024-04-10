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

int ilejed = 0, ilezer = 0;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		char a;
		scanf(" %c", &a);
		if(a == '1')
			++ilejed;
		else
			++ilezer;
	}
	
	if(ilejed)
		ilejed = 1;
		
	while(ilejed--)
		printf("1");
	while(ilezer--)
		printf("0");
	return 0;
}
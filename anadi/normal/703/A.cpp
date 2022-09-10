#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

int main(){
	int n;
	scanf("%d", &n);
	int ilem = 0, ilec = 0;
	for(int i = 1; i <= n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b)
			ilem++;
		if(b > a)
			ilec++;
	}
	
	if(ilem > ilec)
		puts("Mishka");
	if(ilec > ilem)
		puts("Chris");
	if(ilec == ilem)
		puts("Friendship is magic!^^");
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define pb push_back

int main(){
	int n;
	scanf("%d", &n);
	int pos1 = 0;
	int pos2 = 0;
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		if(a == 1)
			pos1 = i;
		if(a == n)
			pos2 = i;
	}
	
	printf("%d\n", max(max(abs(n - pos2), abs(n - pos1)), max(pos2 - 1, pos1 - 1)));
	return 0;
}
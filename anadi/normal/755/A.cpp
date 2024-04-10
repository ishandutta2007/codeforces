#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double DD;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PDD pair <DD, DD>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

int n;

bool prime(int a){
	int i = 2;
	while(i * i <= a){
		if(a%i == 0)
			return false;
		++i;
	}
	
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= 1000; ++i)
		if(!prime(n * i + 1)){
			printf("%d\n", i);
			break;
		}

	return 0;
}
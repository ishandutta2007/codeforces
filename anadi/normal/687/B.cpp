#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define pb push_back
#define LOGN 20

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7;
const int N = 2e5 + 9;

int n, k;

LL nwd(LL a, LL b){
	if(b == 0)
		return a;
	return nwd(b, a%b);
}

LL nww(LL a, LL b){
	return a / nwd(a, b) * b;
}

int main(){
	scanf("%d %d", &n, &k);
	
	LL res = 1LL;
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		res = nww(res, nwd(a, k));
	}
	
	if(res == k)
		puts("Yes");
	else
		puts("No");
	return 0;
}
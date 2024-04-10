#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n;
int r, d;

inline int kwa(int x){
	return x * x;
}

bool solve(int x, int y, int R){
	if(kwa(x) + kwa(y) >= kwa(r - d + R) && kwa(x) + kwa(y) <= kwa(r - R) && 2 * R <= d)
		return true;
	return false;
}

int main(){
	scanf("%d %d", &r, &d);
	scanf("%d", &n);
	
	int res = 0;
	for(int i = 1; i <= n; ++i){
		int x, y, R;
		scanf("%d %d %d", &x, &y, &R);
		if(solve(x, y, R))
			res++;
	}
	
	printf("%d\n", res);
	return 0;
}
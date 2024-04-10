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

int la, ra, ta;
int lb, rb, tb;

int check(int f, int d){
	if(d >= 2 * ta)
		return ra - la + 1;
	
	if(f + d < ta)
		return min(ra, f + d) - max(la, f) + 1;
	
	if(f + d - ta >= ra)
		return ra - la + 1;

	return max(ra - max(la, f), f + d - ta - la) + 1;
}

int main(){
	scanf("%d %d %d", &la, &ra, &ta);
	scanf("%d %d %d", &lb, &rb, &tb);
	
	if(ta > tb){
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	
	int d = __gcd(ta, tb);
	int x = (la - lb%ta + ta)%ta;
	x = (x / d) * d;

	int res = max(check((x + lb)%ta, rb - lb), check((1LL * x + d + lb)%ta, rb - lb));
	printf("%d\n", max(0, res));
	return 0;
}
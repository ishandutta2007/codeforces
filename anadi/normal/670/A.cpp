#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e5 + 7;
const LL INF = 1e9 + 7LL;

int main(){
	int n;
	scanf("%d", &n);
	int x = n / 7;
	int y = n%7;
	if(y == 0)
		printf("%d %d\n", 2 * x, 2 * x);
	if(y == 1)
		printf("%d %d\n", 2 * x, 2 * x + 1);
	if(y < 6 && y > 1)
		printf("%d %d\n", 2 * x, 2 * x + 2);
	if(y == 6)
		printf("%d %d\n", 2 * x + 1, 2 * x + 2);
	return 0;
}
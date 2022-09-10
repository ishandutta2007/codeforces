#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int x1, x2;
int yy1, yy2, a, b;

int main(){
	scanf("%d %d %d %d %d %d", &x1, &x2, &yy1, &yy2, &a, &b);
	x1 -= yy1;
	x2 -= yy2;
	if(x1%a == 0 && x2%b == 0 && abs((x1 / a)%2) == abs((x2 / b)%2))
		puts("YES");
	else
		puts("NO");
	return 0;
}
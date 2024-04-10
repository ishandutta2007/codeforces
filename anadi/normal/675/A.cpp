#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define PLL pair <LL, LL>
#define pb push_back

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(c == 0 && b == a){
		puts("YES");
		return 0;
	}
	if(c == 0 && b != a){
		puts("NO");
		return 0;
	}
	if((b - a) %c == 0 && (b - a)/c >= 0)
		puts("YES");
	else
		puts("NO");
	return 0;
}
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

int n, x1, x2;
PII tab[N];

int solve(int t, int f){
	for(int i = f; i >= 1; --i)
		if(t <= 1LL * tab[i].st * (f - i + 1))
			return i;
	return 0;
}

void write(int f1, int t1, int f2, int t2){
	printf("%d %d\n", t1 - f1 + 1, t2 - f2 + 1);
	for(int i = f1; i <= t1; ++i)
		printf("%d ", tab[i].nd);
	puts("");
	for(int i = f2; i <= t2; ++i)
		printf("%d ", tab[i].nd);
	puts("");
}

int main(){
	scanf("%d %d %d", &n, &x1, &x2);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i].st),
		tab[i].nd = i;
	sort(tab + 1, tab + n + 1);
	
	int p1 = solve(x2, n);
	int p2 = solve(x1, p1 - 1);
	
	if(p2){
		puts("Yes");
		write(p2, p1 - 1, p1, n);
		return 0;
	}
	
	p1 = solve(x1, n);
	p2 = solve(x2, p1 - 1);
	
	if(p2){
		puts("Yes");
		write(p1, n, p2, p1 - 1);
		return 0;
	}
	
	puts("No");
	return 0;
}
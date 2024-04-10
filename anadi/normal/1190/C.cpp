#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;
 
#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;

int n, k;
char s[N];

void First(){
	puts("tokitsukaze");
	exit(0);
}

void Second(){
	puts("quailty");
	exit(0);
}

void Draw(){
	puts("once again");
	exit(0);
}

int main(){
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	
	int mn[2] = {N, N}, mx[2] = {1, 1};
	for(int i = 1; i <= n; ++i){
		mn[s[i] - '0'] = min(mn[s[i] - '0'], i);
		mx[s[i] - '0'] = i;
	}
	
	if(mn[0] == N || mn[1] == N)	First();
	if(mx[0] - mn[0] < k)	First();
	if(mx[1] - mn[1] < k)	First();
	
	if(mx[0] - mn[0] > k)	Draw();
	if(mx[1] - mn[1] > k)	Draw();
	if(k < mn[0] || mx[0] + k <= n)	Draw();
	if(k < mn[1] || mx[1] + k <= n)	Draw();
	
	Second();
	return 0;
}
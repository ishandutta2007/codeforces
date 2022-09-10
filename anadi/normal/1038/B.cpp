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

int n;

int main(){
	scanf("%d", &n);
	LL s = 0LL;
	for(int i = 1; i <= n; ++i)
		s += i;
	
	int t = -1;
	for(int i = 2; 1LL * i * i <= s; ++i)
		if(s%i == 0){
			t = i;
			break;
		}
	
	if(t == -1){
		puts("No");
		return 0;
	}
	
	puts("Yes");
	printf("1 %d\n", t);
	printf("%d ", n - 1);
	for(int i = 1; i <= n; ++i)
		if(i != t)
			printf("%d ", i);

	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;
 
#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;

int n;
int in[N];

void First(){
	puts("sjfnb");
	exit(0);
}

void Second(){
	puts("cslnb");
	exit(0);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);	
	sort(in + 1, in + n + 1);

	if(n == 1){
		if(in[1] & 1)	First();
		else	Second();
	}
	
	int eq = 0;
	for(int i = 1; i + 1 <= n; ++i)
		if(in[i] == in[i + 1]){
			++eq;
			if(i > 1 && in[i - 1] == in[i] - 1)
				Second();
		}
	
	for(int i = 1; i <= n; ++i)
		if(in[i] < i - 1)
			Second();

	if(eq > 1)	
		Second();
	
	LL s = -1LL * n * (n - 1) / 2;
	for(int i = 1; i <= n; ++i)
		s += in[i];
	
	if(s%2 == 1)
		First();
	else
		Second();
	return 0;
}
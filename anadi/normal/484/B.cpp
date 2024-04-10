#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, res = 0;
bool is[N];
int prv[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		is[a] = true;
	}
	
	int last = 0;
	for(int i = 1; i < N; ++i){
		prv[i] = last;
		if(is[i])
			last = i;
	}
	
	for(int i = 1; i < N; ++i){
		if(!is[i])
			continue;
		
		for(int j = i + i; j < N; j += i){
			int p = prv[j];
			res = max(res, p + i - j);
		}
	}

	printf("%d\n", res);
	return 0;
}
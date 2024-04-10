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
int in[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	
	int m = 1 << n;
	for(int i = 0; i < m; ++i){
		int cur = 0;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				cur += in[j];
			else
				cur -= in[j];
		
		cur %= 360;
		if(cur == 0){
			puts("YES");
			return 0;
		}
	}
	
	puts("NO");
	return 0;
}
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

int res;
int n, m, l;
LL length[N];

int main(){
	scanf("%d %d %d", &n, &m, &l);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &length[i]);
	
	for(int i = 1; i <= n; ++i){
		res += length[i] > l;
		res -= length[i] > l && length[i - 1] > l;
	}
	
	while(m--){
		int t;
		scanf("%d", &t);
		
		if(t == 0)
			printf("%d\n", res);
		else{
			int p, d;
			scanf("%d %d", &p, &d);
			
			if(length[p] <= l && length[p] + d > l){
				++res;
				res -= length[p - 1] > l;
				res -= length[p + 1] > l;
			}
			
			length[p] += d;
		}
	}

	return 0;
}
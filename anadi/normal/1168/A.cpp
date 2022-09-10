#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int in[N];

bool check(int a){
	int last = 0;
	for(int i = 1; i <= n; ++i){
		int v = in[i], v2 = in[i] + a;
		if(v2 < last)
			return false;

		if(v2 >= m)
			v2 -= m;
		
		if(v2 < last)
			last = max(last, v);
		else if(v <= v2)
			last = max(last, v);
	}
	
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	int p = 0, k = m - 1;
	while(p < k){
		int mid = (p + k) / 2;
		if(check(mid))
			k = mid;
		else
			p = mid + 1;
	}
	
	printf("%d\n", p);
	return 0;
}
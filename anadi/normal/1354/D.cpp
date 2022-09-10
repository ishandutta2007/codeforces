#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, q;
int in[N];
int query[N];

bool check(int val){
	int cur = 0;
	for(int i = 1; i <= n; ++i)
		if(in[i] <= val)
			++cur;
	
	for(int i = 1; i <= q; ++i){
		if(query[i] < 0){
			if(-query[i] <= cur)
				cur--;
		}
		else if(query[i] <= val)
			++cur;
	}
	
	return cur > 0;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i <= q; ++i)
		scanf("%d", &query[i]);
	
	int s = 1, e = n + 1;
	while(s < e){
		int mid = (s + e) / 2;
		if(check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	
	if(s <= n)
		printf("%d\n", s);
	else
		puts("0");
	return 0;
}
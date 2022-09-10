#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int cnt[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		while(a--){
			int b;
			scanf("%d", &b);
			cnt[b]++;
		}
	}
	
	for(int i = 1; i <= 100; ++i)
		if(cnt[i] == n)
			printf("%d ", i);
	return 0;
}
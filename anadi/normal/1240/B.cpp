#include <bits/stdc++.h>

using namespace std;

typedef long double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int First[N], Last[N];

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		First[i] = n + 1, Last[i] = 0;

	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);

		First[a] = min(First[a], i);
		Last[a] = max(Last[a], i);
	}
	
	int mx = 0, sum = 0;
	int prv = 0, cur = 0;
	for(int i = 1; i <= n; ++i){
		if(Last[i] == 0)	
			continue;
		++sum;
		
		if(prv <= First[i])
			++cur;
		else
			cur = 1;

		prv = Last[i];
		mx = max(mx, cur);
	}
	
	printf("%d\n", sum - mx);
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}
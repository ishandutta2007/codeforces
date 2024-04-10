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
int dp[N];
vector <int> dv[N];

void add(int &a, int b){
	a += b;
	if(a >= MX)
		a -= MX;
}

int main(){
	for(int i = 1; i < N; ++i){
		for(int j = i; j < N; j += i)
			dv[j].push_back(i);
		reverse(dv[i].begin(), dv[i].end());
	}
	
	dp[0] = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int v;
		scanf("%d", &v);
		
		for(int t: dv[v])
			add(dp[t], dp[t - 1]);
	}
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
		add(res, dp[i]);
	printf("%d\n", res);
	return 0;
}
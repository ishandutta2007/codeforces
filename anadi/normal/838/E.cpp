#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;

#define st first
#define nd second
#define PII pair <int, int>
#define PDD pair <LD, LD>

const int N = 2507;

int n;
PDD odl[N];
long double dp[N][N][2];

inline long double kwa(double x){
	return x * x;
}

inline long double dist(int a, int b){
	return sqrt(kwa(odl[a].st - odl[b].st) + kwa(odl[a].nd - odl[b].nd));
}

inline int who(int u){
	if(u > n)
		return u - n;
	if(u < 1)
		return u + n;
	return u;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%Lf %Lf", &odl[i].st, &odl[i].nd);
	
	for(int l = 1; l < n; ++l)
		for(int j = 1; j <= n; ++j){
			int i = j; j = who(i + l);
			dp[i][j][0] = max(dp[who(i + 1)][j][0] + dist(i, who(i + 1)), dp[who(i + 1)][j][1] + dist(i, j));
			dp[i][j][1] = max(dp[i][who(j - 1)][1] + dist(who(j - 1), j), dp[i][who(j - 1)][0] + dist(i, j));
			j = i;
		}
	
	long double res = max(dp[1][n][0], dp[1][n][1]);
	for(int i = 2; i <= n; ++i)
		res = max(res, max(dp[i][i - 1][0], dp[i][i - 1][1]));
	printf("%.10Lf\n", res);
	return 0;
}
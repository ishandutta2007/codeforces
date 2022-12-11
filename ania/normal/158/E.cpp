#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

#define maxn 4040

pair<int,int> t[maxn];
int dp[maxn][maxn];

int main()
{
	int N,K,res=0;
	scanf("%d%d", &N, &K);
	FOR(i,N) scanf("%d%d", &t[i].fi, &t[i].se);
	sort(t,t+N);
	FOR(i,K+1) dp[0][i] = 1;
	for(int n = 1; n <= N; n++)
	{
		dp[n][0] = max(dp[n-1][0], t[n-1].fi) + t[n-1].se;
		//printf("dp[%d][0] = %d\n", n, dp[n][0]);
		for(int k = 1; k <= K; k++)
		{
			dp[n][k] = min(dp[n-1][k-1], max(dp[n-1][k], t[n-1].fi) + t[n-1].se);
			//printf("dp[%d][%d] = %d\n", n, k, dp[n][k]);
		}
	}
	t[N].fi = 86401;
	FOR(i,N+1)
	{
		res = max(res, t[i].fi - dp[i][K]);
		//printf("i = %d, res = %d\n", i, res);
	}
	printf("%d\n", res);
	return 0;
}
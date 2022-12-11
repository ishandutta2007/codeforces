#include<bits/stdc++.h>

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

int n;
int c[555];
int dp[555][555];

int rec(int lo, int hi) {
	if (dp[lo][hi]) return dp[lo][hi];
	if (lo==hi) return 0;
	if (lo+1 == hi) return dp[lo][hi] = 1;
	if (lo+2 == hi) {
		if (c[lo]==c[lo+1]) return dp[lo][hi] = 1;
		return dp[lo][hi] = 2;
	}
	int res = hi-lo;
	if (c[lo] == c[hi-1]) res = rec(lo+1, hi-1);
	for (int mi = lo+1; mi < hi; mi++)
		res = min(res, rec(lo,mi) + rec(mi,hi));
	return dp[lo][hi] = res;
}

int main() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &c[i]);
	printf("%d\n", rec(0,n));
	return 0;
}
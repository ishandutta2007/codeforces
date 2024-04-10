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

const int maxn = 5050;
const int mod = 1000000007;
const int inf = mod;

int n;
char s[maxn];
int dp[maxn][maxn], sumdp[maxn][maxn];
int diff[maxn][maxn];

int chk(int last, int pos) {
	if (pos==n) return -inf;
	if (diff[last][pos] != 0) return diff[last][pos];
	if (s[last] != s[pos]) {
		if (s[last]<s[pos]) return diff[last][pos]=1;
		return diff[last][pos] = -1;
	}
	int res = chk(last+1, pos+1);
	if (res==-inf) return diff[last][pos] = res;
	if (res<0) return diff[last][pos] = res-1;
	return diff[last][pos] = res+1;
}

int rec(int pos, int last) {
	int minlen = max(1,pos-last);
	int res=0;
	for (int len = minlen; pos+len <= n; len++) {
		if (len > pos-last || chk(last,pos)) res += rec(pos+len, pos);
		if (res>=mod) res -= mod;
	}
	//printf("rec %d %d = %d\n", pos, last, dp[pos][last]);
	return dp[pos][last] = res;
}

int main() {
	scanf("%d %s", &n, s);
	for (int last = 0; last < n; last++) dp[n][last] = sumdp[n][last] = 1;
	for (int pos = n-1; pos >= 0; pos--) {
		for (int last = 0; last < pos; last++) {
			if (s[pos] == '0') {
				dp[pos][last] = 0;
				sumdp[pos][last] = dp[pos][last] + sumdp[pos+1][last];
				if (sumdp[pos][last] >= mod) sumdp[pos][last] -= mod;
				continue;
			}
			int len = pos-last;
			if (pos+len <= n) {
				int tmp = chk(last,pos);
				if (tmp>0 && tmp<=len) dp[pos][last] += dp[pos+len][pos];
			}
			if (dp[pos][last] >= mod) dp[pos][last] -= mod;
			//for (int ri = pos+len+1; ri <= n; ri++) dp[pos][last] += dp[ri][pos];
			if (pos+len+1 <= n) dp[pos][last] += sumdp[pos+len+1][pos];
			if (dp[pos][last] >= mod) dp[pos][last] -= mod;
			sumdp[pos][last] = dp[pos][last] + sumdp[pos+1][last];
			if (sumdp[pos][last] >= mod) sumdp[pos][last] -= mod;
			//printf("%d %d -- %d %d\n", pos, last, dp[pos][last], sumdp[pos][last]);
		}
	}
	printf("%d\n", sumdp[1][0]);
	return 0;
}
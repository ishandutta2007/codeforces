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

int dp[222][222][222];

int rec(int r, int g, int b) {
	if (dp[r][g][b]) return dp[r][g][b];
	int re = 0;
	if (r>=2) re |= rec(r-1,g,b);
	if (g>=2) re |= rec(r,g-1,b);
	if (b>=2) re |= rec(r,g,b-1);
	if (r&&g) re |= rec(r-1,g-1,b+1);
	if (r&&b) re |= rec(r-1,g+1,b-1);
	if (b&&g) re |= rec(r+1,g-1,b-1);
	if (r+g+b==1) {
		if (r) re=4;
		if (g) re=2;
		if (b) re=1;
	}
	return dp[r][g][b] = re;
}

char s[222];

int main() {
	int n,r=0,g=0,b=0;
	scanf("%d %s", &n, s);
	FOR(i,n) {
		if (s[i]=='R') r++;
		if (s[i]=='G') g++;
		if (s[i]=='B') b++;
	}
	rec(r,g,b);
	if (dp[r][g][b]&1) printf("B");
	if (dp[r][g][b]&2) printf("G");
	if (dp[r][g][b]&4) printf("R");
	printf("\n");
	return 0;
}
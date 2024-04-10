#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
char s[N], t[N];
int n, m, nxt[N], trans[N][26];
VI dp[N];
void getnxt() {
	int j = 0;
	rep(i, 2, n) {
		while(j && t[j + 1] != t[i]) j = nxt[j];
		if(t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
	rep(j, 0, m) rep(c, 0, 25) {
		int nj = j;
		while(nj && t[nj + 1] != c + 'a') nj = nxt[nj];
		if(t[nj + 1] == c + 'a') nj++;
		trans[j][c] = nj;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	getnxt();
	rep(i, 0, n) dp[i].resize(m + 1, -inf);
	dp[0][0] = 0;
	rep(i, 1, n) rep(j, 0, m) {
		char l = 'a', r = 'z';
		if(s[i] != '?') l = r = s[i];
		for(char ch = l; ch <= r; ch++) {
			int nj = trans[j][ch - 'a'];
			dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + (nj == m));
		}
	}
	printf("%d\n", *max_element(all(dp[n])));
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define B 447
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
int n, m, q, dp[2][N], f[N][B + 30];
pii S[N];
void cmax(int &x, int y) {
	if(x < y) x = y;
}
void cmin(int &x, int y) {
	if(x > y) x = y;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	bool flag = 0;
	if(n < m) swap(n, m), flag = 1;
	scanf("%d", &q);
	rep(i, 1, q) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(flag) swap(x, y);
		S[i] = mp(x, y);
	}
	sort(S + 1, S + q + 1);
	if(n <= m * B) {
		rep(_, 0, 1) rep(i, 1, n) dp[_][i] = -inf;
		dp[0][1] = 1;
		int cur = 0, nxt = 1;
		rep(_, 0, B + 100) {
			if(dp[cur][n] == m) return printf("%d\n", _), 0;
			int ptr = 1;
			rep(i, 1, n) {
				while(ptr + 1 <= q && S[ptr] < mp(i, dp[cur][i])) ptr++;
				int ni = i + dp[cur][i] + (S[ptr] == mp(i, dp[cur][i]));
				if(ni > 0) cmax(dp[nxt][min(ni, n)], dp[cur][i]);
				if(ni > 0) cmax(dp[nxt][i], min(ni, m));
			}
			rep(i, 1, n) dp[cur][i] = -inf;
			swap(cur, nxt);
		}
	}
	memset(f, 0x3f, sizeof f);
	f[1][1] = 0;
	rep(i, 1, n) {
		int ptr = lower_bound(S + 1, S + q + 1, mp(i, 0)) - S;
		ptr = min(ptr, q);
		rep(j, 1, m) {
			while(ptr + 1 <= q && S[ptr].se < j && S[ptr + 1].fi == i) ptr++;
			int w = S[ptr] == mp(i, j);
			cmin(f[min(n, i + j + w)][j], f[i][j] + 1);
			cmin(f[i][min(m, i + j + w)], f[i][j] + 1);
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}
/*
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)
n > m
f(m, m) = O(log(m))
f(n, m) <= O(log(m)) + O(n / m)
*/
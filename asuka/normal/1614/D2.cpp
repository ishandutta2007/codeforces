#include<bits/stdc++.h>
#define ll long long
#define N 20000015
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
int pri[N], tot, low[N];
bool notp[N];
void getpri() {
	rep(i, 2, 20000000) {
		if(!notp[i]) {pri[++tot] = i; low[i] = i;}
		for(int j = 1; j <= tot && i * pri[j] <= 20000000; ++j) {
			notp[i * pri[j]] = 1;
			low[i * pri[j]] = pri[j];
			if(i % pri[j] == 0) break;
		}
	}
}
int n, cnt[N];
ll dp[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	getpri();
	scanf("%d", &n);
	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		for(int j = 1; j * j <= x; ++j) {
			if(x % j) continue;
			cnt[j]++;
			if(j * j != x) cnt[x / j]++;
		}
	}
	per(i, 1, 20000000) {
		dp[i] = max(dp[i], (ll) cnt[i] * i);
		int x = i;
		while(x > 1) {
			int u = low[x];
			dp[i / u] = max(dp[i / u], dp[i] + (ll) (cnt[i / u] - cnt[i]) * (i / u));
			while(x % u == 0) x /= u;
		}
	}
	printf("%lld\n", dp[1]);
	return 0;
}
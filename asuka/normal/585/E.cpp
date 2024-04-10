#include<bits/stdc++.h>
#define ll long long
#define N 500015
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
using namespace std;
const int M = 1e7 + 5, mod = 1e9 + 7;
int pri[1000005], mu[M], tot, low[M];
bool notp[M];
void inc(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}
void dec(int &x, int y) {
	x -= y;
	if(x < 0) x += mod;
}
void sieve() {
	mu[1] = 1;
	rep(i, 2, 10000000) {
		if (!notp[i]) {pri[++tot] = i; mu[i] = -1; low[i] = i;}
		for (int j = 1; j <= tot && i * pri[j] <= 10000000; ++j) {
			notp[i * pri[j]] = 1;
			low[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
			else mu[i * pri[j]] = -mu[i];
		}
	}
}
int n, a[N], cnt[M], pd[N], f[M], bucket[M], g[M];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	sieve();
	scanf("%d", &n);
	pd[0] = 1;
	rep(i, 1, n) pd[i] = pd[i - 1] * 2 % mod;
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		bucket[a[i]]++;
	}
	rep(i, 1, 10000000) {
		for (int j = 1; j * i <= 10000000; ++j) {
			cnt[i] += bucket[j * i];
		}
	}
	rep(i, 1, 10000000) {
		for (int j = 1; j * i <= 10000000; ++j) {
			if(mu[i] == 1) inc(g[i * j], cnt[i]);
			if(mu[i] == -1) dec(g[i * j], cnt[i]);
		}
	}
	int res = 0;
	rep(i, 2, 10000000) {
		for (int j = 1; j * i <= 10000000; ++j) {
			if(mu[j] == 1) inc(f[i], pd[cnt[i * j]] - 1);
			if(mu[j] == -1) dec(f[i], pd[cnt[i * j]] - 1);
		}
		inc(res, (ll) f[i] * g[i] % mod);
	}
	printf("%d\n", res);
	return 0;
}
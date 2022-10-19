#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define B 3800
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
char s[N];
int n, pre[N];
ll ans = 0;
map<ll, int> M;
int main() {
	// freopen("F.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	// #1 <= B
	clock_t st = clock();
	VI vec;
	vec.pb(0);
	rep(i, 1, n) if (s[i] == '1') vec.pb(i);
	vec.pb(n + 1);
	rep(i, 1, SZ(vec) - 2) {
		rep(j, i, min(SZ(vec) - 2, i + B - 1)) {
			int l1 = vec[i - 1] + 1, l = vec[i], r = vec[j], r1 = vec[j + 1] - 1;
			rep(k, r, r1) {
				int llen = k - l + 1, rlen = k - l1 + 1;
				ans += rlen / (j - i + 1) - (llen - 1) / (j - i + 1);
			}
		}
	}
	cerr << (1.0 * clock() - st) / CLOCKS_PER_SEC << endl;
	st = clock();
	// #1 > B
	rep(i, 1, n) pre[i] = pre[i - 1] + (s[i] == '1');
	rep(k, 1, n / B) {
		M.clear();
		rep(i, 1, SZ(vec) - 2) {
			if (i - B > 0) {
				int tl1 = vec[i - B - 1], tl = vec[i - B] - 1;
				rep(j, tl1, tl) M[(ll) k * pre[j] - j]++;
			}
			int r = vec[i], r1 = vec[i + 1] - 1;
			rep(j, r, r1) ans += M[(ll) k * pre[j] - j];
		}
	}
	cerr << (1.0 * clock() - st) / CLOCKS_PER_SEC << endl;
	printf("%lld\n", ans);
	return 0;
}
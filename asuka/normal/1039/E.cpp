#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
int A, B;
int n, w, q, a[N], nxt[N], jump[N], cnt[N], Max[N], Min[N], res[N];
pii ask[N];
priority_queue<pii> Q;
namespace RMQ {
	int Max[N][21], Min[N][21], Log[N];
	void init(){
		rep(i, 1, n) Max[i][0] = Min[i][0] = a[i];
		rep(i, 2, n) Log[i] = Log[i >> 1] + 1;
		rep(j, 1, 19) rep(i, 1, n) if(i + (1 << j) - 1 <= n) {
			Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
			Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
		}
	}
	int qmax(int l, int r) {
		int K = Log[r - l + 1];
		return max(Max[l][K], Max[r - (1 << K) + 1][K]);
	}
	int qmin(int l, int r) {
		int K = Log[r - l + 1];
		return min(Min[l][K], Min[r - (1 << K) + 1][K]);
	}
}
int dif(int l, int r){
	return RMQ::qmax(l, r) - RMQ::qmin(l, r);
}
void fix(int x, int lim) {
	while(nxt[x] <= n && nxt[x] <= x + B && Max[x] - Min[x] <= lim) {
		nxt[x]++;
		if(nxt[x] <= n) {
			Max[x] = max(Max[x], a[nxt[x]]);
			Min[x] = min(Min[x], a[nxt[x]]);
		}
	}
}
int vis[N], last[N];
void modify(int x, int lim) { // expand typ A
	VI stk;
	fix(x, lim);
	if(nxt[x] <= n && nxt[x] <= x + A) {
		Q.push(mp(Min[x] - Max[x], x));
	}
	jump[x] = x;
	cnt[x] = 0;
	stk.pb(x);
	while(nxt[jump[x]] <= x + A && jump[x] <= n) {
		fix(jump[x], lim);
		jump[x] = nxt[jump[x]];
		stk.pb(jump[x]);
		cnt[x]++;
	}
	last[x] = SZ(stk);
	vis[x] = 1;
	per(i, max(1, x - A), x - 1) {
		fix(i, lim);
		if(nxt[i] <= n && vis[nxt[i]]) {
			while(stk.back() > i + A) stk.pop_back();
			jump[i] = stk.back();
			cnt[i] = cnt[nxt[i]] + 1 + SZ(stk) - last[nxt[i]];
			last[i] = SZ(stk);
			vis[i] = 1;
		}
	}
	per(i, max(1, x - A), x) vis[i] = 0;
}
int query(int lim) {
	while(!Q.empty() && -Q.top().fi <= lim) {
		int tmp = Q.top().se;
		Q.pop();
		modify(tmp, lim);
		
	}
	int x = 1, ans = 0;
	while(x <= n) {
		fix(x, lim);
		if(nxt[x] <= x + A) {
			ans += cnt[x];
			x = jump[x];
		} else {
			ans++;
			if(nxt[x] <= x + B) {
				x = nxt[x];
			} else {
				int l = x, r = n, ljump = 0;
				while(l <= r) {
					int mid = (l + r) >> 1;
					if(dif(x, mid) <= lim) ljump = mid, l = mid + 1;
					else r = mid - 1;
				}
				assert(ljump != 0);
				x = ljump + 1;
			}
		}
	}
	return ans - 1;
}	
int main(){
	// freopen("E.in","r",stdin);
	// freopen("E.out","w",stdout);
	scanf("%d%d%d", &n, &w, &q);
	A = (int) pow(n, 1.0 / 3);
	B = (int) pow(n, 2.0 / 3);
	rep(i, 1, n) scanf("%d", &a[i]);
	RMQ::init();
	rep(i, 1, q) {
		scanf("%d", &ask[i].fi);
		ask[i].fi = w - ask[i].fi;
		ask[i].se = i;
	}
	rep(i, 1, n){
		nxt[i] = i + 1;
		if(nxt[i] <= n){
			Max[i] = max(a[i], a[i + 1]);
			Min[i] = min(a[i], a[i + 1]);
			Q.push(mp(Min[i] - Max[i], i));
		}
		jump[i] = min(i + A, n + 1);
		cnt[i] = jump[i] - i;
	}
	sort(ask + 1, ask + q + 1);
	rep(i, 1, q) {
		res[ask[i].se] = query(ask[i].fi);
	}
	rep(i, 1, q)
		printf("%d\n", res[i]);
	return 0;
}
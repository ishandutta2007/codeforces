#include<bits/stdc++.h>
#define ll long long
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
const int N = 500015;
int n, q, a[N], ans[N], occ[N], vis[N];
vector<pii> ql[N], qr[N];
set<pii> S;
void solve(int l, int r)  {
	if(l == r) {
		for(auto x : ql[l]) if(x.fi == r) ans[x.se] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	rep(i, mid + 1, r) {
		if(!occ[a[i]]) occ[a[i]] = i;
	}
	per(i, l, mid) {
		if(vis[a[i]] == 0) vis[a[i]] = 1, S.insert(mp((occ[a[i]] == 0 ? n + 1 : occ[a[i]]) - 1, a[i]));
		else if(vis[a[i]] == 1) vis[a[i]] = 2, S.erase(mp((occ[a[i]] == 0 ? n + 1 : occ[a[i]]) - 1, a[i]));
		while(SZ(ql[i]) > 0 && ql[i].back().fi > mid) {
			int r = ql[i].back().fi, id = ql[i].back().se;
			ql[i].pop_back();
			if(SZ(S) > 0 && S.rbegin() -> fi >= r) {
				ans[id] = S.rbegin() -> se;
			} 
		}
	}
	rep(i, mid + 1, r) occ[a[i]] = 0;
	rep(i, l, mid) vis[a[i]] = 0;
	S.clear();
	per(i, l, mid) {
		if(!occ[a[i]]) occ[a[i]] = i;
	}
	rep(i, mid + 1, r) {
		if(vis[a[i]] == 0) vis[a[i]] = 1, S.insert(mp(occ[a[i]] + 1, a[i]));
		else if(vis[a[i]] == 1) vis[a[i]] = 2, S.erase(mp(occ[a[i]] + 1, a[i]));
		while(SZ(qr[i]) > 0 && qr[i].back().fi <= mid) {
			int l = qr[i].back().fi, id = qr[i].back().se;
			qr[i].pop_back();
			if(SZ(S) > 0 && S.begin() -> fi <= l) {
				ans[id] = S.begin() -> se;
			} 
		}
	}
	rep(i, l, mid) occ[a[i]] = 0;
	rep(i, mid + 1, r) vis[a[i]] = 0;
	S.clear();
	solve(l, mid);
	solve(mid + 1, r);
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	scanf("%d", &q);
	rep(i, 1, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		ql[l].emplace_back(r, i);
		qr[r].emplace_back(l, i);
	}
	rep(i, 1, n) {
		sort(all(ql[i]));
		sort(all(qr[i]));
		reverse(all(qr[i]));
	}
	solve(1, n);
	rep(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}
/*
10
5 9 6 4 8 7 4 9 7 6
1
4 7
*/
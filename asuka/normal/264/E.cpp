#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int n, m;
struct seg {
#define ls (p << 1)
#define rs (p << 1 | 1)
	int Max[N << 2];
	void pushup(int p) {Max[p] = max(Max[ls], Max[rs]);}
	void modify(int p, int l, int r, int pos, int val) {
		if (l == r) {
			Max[p] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) modify(ls, l, mid, pos, val);
		else modify(rs, mid + 1, r, pos, val);
		pushup(p);
	}
	int query(int p, int l, int r, int x, int y) {
		if (x <= l && r <= y) {
			return Max[p];
		}
		int res = 0, mid = (l + r) >> 1;
		if (x <= mid) res = max(res, query(ls, l, mid, x, y));
		if (y > mid) res = max(res, query(rs, mid + 1, r, x, y));
		return res;
	}
} T1, T2; //  
int dp[N];
vector<pii> qry, tmp;
set<pii> S;
void plant(int pos, int val) {
	for (auto x : qry) {
		if(x.se < val) {
			// printf("DEL: %d %d %d\n", x.fi, x.se, dp[x.fi]);
			T2.modify(1, 1, n, x.fi, 0);
			T1.modify(1, 1, m + 10, x.se, 0);
			dp[x.fi] = 0;
		}
	}
	int v = T2.query(1, 1, n, pos, n);
	T2.modify(1, 1, n, pos, v + 1);
	T1.modify(1, 1, m + 10, val, v + 1);
	// printf("plant %d\n", v + 1);
	S.insert(mp(pos, val));
	dp[pos] = v + 1;
	tmp.clear();
	for (auto x : qry) {
		if(x.se < val) {
			tmp.pb(x);
		}
	}
	sort(all(tmp));
	per(i, 0, SZ(tmp) - 1) {
		int cur = T2.query(1, 1, n, tmp[i].fi + 1, n);
		rep(j, i + 1, SZ(tmp) - 1) {
			if (tmp[i].se < tmp[j].se) cur = max(cur, dp[tmp[j].fi]);
		}
		// printf("CUR: %d %d %d\n", tmp[i].fi, tmp[i].se, cur + 1);
		dp[tmp[i].fi] = cur + 1;
	}
	rep(i, 0, SZ(tmp) - 1) {
		int cur = dp[tmp[i].fi];
		T1.modify(1, 1, m + 10, tmp[i].se, cur);
		T2.modify(1, 1, n, tmp[i].fi, cur);
	}
	if (SZ(qry) == 10) {
		qry.erase(qry.begin());
	}
	qry.pb(mp(pos, val));
}
void cut(int pos) {
	auto u = S.begin();
	rep(i, 1, pos - 1) u++;
	pos = (*u).fi;
	int val = (*u).se;
	S.erase(u);
	T2.modify(1, 1, n, pos, 0); dp[pos] = 0;
	T1.modify(1, 1, m + 10, val, 0);
	tmp.clear();
	for (auto it = S.begin(); it != S.end() && (*it).fi < pos; it++) {
		tmp.pb(*it);
	}
	for(auto x : tmp) {
		T1.modify(1, 1, m + 10, x.se, 0);
		T2.modify(1, 1, n, x.fi, 0);
		dp[x.fi] = 0;
	}
	per(i, 0, SZ(tmp) - 1) {
		int cur = T1.query(1, 1, m + 10, tmp[i].se + 1, m + 10);
		rep(j, i + 1, SZ(tmp) - 1) {
			if(tmp[i].se < tmp[j].se) cur = max(cur, dp[tmp[j].fi]);
		}
		dp[tmp[i].fi] = cur + 1;
	}
	rep(i, 0, SZ(tmp) - 1) {
		int cur = dp[tmp[i].fi];
		T1.modify(1, 1, m + 10, tmp[i].se, cur);
		T2.modify(1, 1, n, tmp[i].fi, cur);
	}
	for(auto it = qry.begin(); it != qry.end(); ++it) {
		if((*it).fi == pos && (*it).se == val) {
			qry.erase(it);
			break;
		}
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	per(_, 1, m) {
		int opt, x, y;
		scanf("%d%d", &opt, &x);
		if (opt == 1) {
			scanf("%d", &y);
			plant(x, y + _);
		} else cut(x);
		printf("%d\n", T1.query(1, 1, m + 10, 1, m + 10));
	}
	return 0;
}

/*
5 5
1 4 7
1 3 10
1 2 2
1 1 6
1 5 10
*/
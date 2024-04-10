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
int n, k, x[N], y[N];
vector<pii> a;
pii check(int u, int v) {
	int cnt = 0, pos = -1;
	rep(i, 1, n) {
		if ((ll) (y[i] - y[u]) * (x[v] - x[u]) - (ll) (y[v] - y[u]) * (x[i] - x[u]) != 0) {
			cnt++;
			pos = i;
		}
	}
	return mp(cnt, pos);
}
double dis(pii u, pii v) {
	return sqrt((double) (u.fi - v.fi) * (u.fi - v.fi) + (double) (u.se - v.se) * (u.se - v.se));
}
double D[N], val[N];
double solve(vector<pii> vec, pii P, int pos) {
	
	// printf("POINTS:\n");
	// for(auto x : vec) printf("(%d %d)\n", x.fi, x.se);
	// printf("P\n");
	// printf("(%d %d)\n", P.fi, P.se);
	// printf("START:\n");
	// if(~pos) printf("(%d %d)\n", vec[pos].fi, vec[pos].se);
	// else printf("(%d %d)\n", P.fi, P.se);

	double ans = 1e20;
	int m = SZ(vec);
	rep(i, 0, m - 1) D[i] = dis(vec[i], P) + dis(vec[i], vec[0]) + dis(vec[i], vec[m - 1]) + min(dis(vec[i], vec[0]), dis(vec[i], vec[m - 1]));
	double md = *min_element(D, D + m);
	if(pos == -1) return md;
	rep(i, 0, m - 1) {
		if(pos <= i) {
			ans = min(ans, dis(vec[0], vec[i]) + min(dis(vec[i], vec[pos]) + dis(vec[0], P), dis(vec[0], vec[pos]) + dis(vec[i], P)) + ((i + 1 < m) ? (dis(vec[i + 1], P) +  dis(vec[i + 1], vec[m - 1])) : 0));
		}
	}
	// ans = min(ans, dis(vec[0], vec[pos]) + dis(vec[0], P) + ((pos + 1 < m) ? (dis(P, vec[pos + 1]) + dis(vec[pos + 1], vec[m - 1])) : 0));
	return ans;
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	auto tmp = check(1, 2);
	// printf("WERTUI %d %d\n", tmp.fi, tmp.se);
	int ptr = 1;
	if(tmp.fi == 1) {
		ptr = tmp.se;
	} else {
		tmp = check(1, 3);
		if(tmp.fi == 1) ptr = tmp.se;
		else ptr = 1;
	}
	rep(i, 1, n) if(i != ptr) a.pb(mp(x[i], y[i]));
	sort(all(a));
	int nk = (k == ptr) ? -1 : k, pos = -1;
	if(nk == -1) pos = -1;
	else {
		rep(i, 0, SZ(a) - 1) if(a[i].fi == x[nk] && a[i].se == y[nk]) pos = i;
	}
	double res = solve(a, mp(x[ptr], y[ptr]), pos);
	reverse(all(a));
	res = min(res, solve(a, mp(x[ptr], y[ptr]), (pos == -1) ? -1 : (SZ(a) - pos - 1)));
	// if(n == 20203) {
	// 	printf("%d %d\n", pos, (pos == -1) ? -1 : (SZ(a) - pos - 1));
	// 	printf("%d %d\n", x[ptr], y[ptr]);
	// 	printf("%lf %lf\n",  solve(a, mp(x[ptr], y[ptr]), pos), solve(a, mp(x[ptr], y[ptr]), (pos == -1) ? -1 : (SZ(a) - pos - 1)));
	// }
	printf("%lf\n", res);
	return 0;
}
/*
8 3
-4 0
-3 0
-1 0
1 0
2 0
4 0
5 0
5 10
*/